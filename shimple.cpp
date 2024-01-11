#include <iostream>
#include <unistd.h>
#include "shimple.h"
#include <sys/wait.h>

using namespace std;

Shimple::Shimple() {
     // Clear terminal
    #if defined(_WIN32)
        system("cls");
    #elif defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
}

void Shimple::shi_start() {
    string line;
    vector <string> args;
    int status;

    do {
        cout << "SHIMPLE >> ";

        line = shi_get_line();
        if (line.empty()) continue;

        args = shi_split_line(line);
        status = shi_execute(args);

    } while (status);
}

string Shimple::shi_get_line() {
    string line;

    if (getline(cin, line))
        return line;

    if (cin.eof()) {
        cout << "EOF encountered\n";
        exit(0);
    } else if (cin.fail() || cin.bad()) {
        cout << "Error occurred while reading input...\n";
        exit(-1);
    } 

    return "";
}


vector<string> Shimple::shi_split_line(string line) {
    vector<string> args;
    char *tok = strtok(const_cast<char*>(line.c_str()), " ");

    while (tok != nullptr) {
        cout << tok << endl;
        args.push_back(string(tok));
        tok = strtok(nullptr, " ");  // Nullptr
    }

    return args;
}


int Shimple::shi_launch(vector<string> args) {
    pid_t pid, wpid;
    int status;

    // Convert args to a char**
    char **cArgs = new char*[args.size() + 1];  // +1 for null terminator

    for (int i = 0; i < args.size(); i++) {
        cArgs[i] = new char[args[i].size() + 1];   // +1 for null terminator
        strcpy(cArgs[i], args[i].c_str());
    }

    cArgs[args.size()] = NULL;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(cArgs[0], cArgs) == -1) {
            // If it returns you know something has gone wrong...
            cerr << "Error occurred while executing: " << cArgs[0] << endl;
            exit(-1);
        }
    } else if (pid < 0) {
        // Error forking
        cerr << "SHIMPLE" << endl;
    } else {
        // Parent process
        do {
            // Use waitpid to wait until the child process has either exited or killed.
            // Remember that pid is the process id of the child process.
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}


int Shimple::shi_execute(std::vector<std::string> args) {
    
    return 1;
}


int main(void) {
    Shimple sh;

    sh.shi_start();

    return 0;
}
