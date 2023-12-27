#include <iostream>
#include "shimple.h"

using namespace std;
Shimple::Shimple() {
    cout << "Welcome to simple shell\n";
}

void Shimple::shi_loop() {
    string line;
    string *args;
    int status;

    do {
        line = shi_get_line();

    } while (status);
}

string Shimple::shi_get_line() {
    
}

int main(void) {
    Shimple sh;

    sh.shi_loop();

    return 0;
}
