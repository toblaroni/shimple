#include <iostream>
#include "shimple.h"

using namespace std;

Shimple::Shimple() {
     // Clear terminal
    #if defined(_WIN32)
        system("cls");
    #elif defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
}

void Shimple::shi_loop() {
    string line;
    vector <string> args;
    // int status = 1;

    do {
        cout << "SHIMPLE >> ";

        line = shi_get_line();
        if (line.empty()) continue;

        args = shi_split_line(line);

    } while (1);
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


int main(void) {
    Shimple sh;

    sh.shi_loop();

    return 0;
}