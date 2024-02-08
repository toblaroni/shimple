#ifndef SHIMPLE_H
#define SHIMPLE_H

#define SHI_EXIT_BAD_EXECUTION -1
#define SHI_EXIT_BAD_INPUT     -2

#include <string.h>
#include <vector>
#include <string>

class Shimple {

public:
    Shimple();
    void shi_start();

    // Declarations for builtin functions
    int shi_cd(std::vector<std::string>);
    int shi_help(std::vector<std::string>);
    int shi_exit(std::vector<std::string>);
    int shi_num_builtins();

private:

    std::vector<std::string> builtin_str = {
        "cd",
        "help",
        "exit"
    };

    // Function pointers for builtin commands
    // It's an array of function pointers
    // Which each take an array of strings and return an int
    int (Shimple::*builtin_func[3]) (std::vector<std::string>) = { 
        &Shimple::shi_cd,
        &Shimple::shi_help,
        &Shimple::shi_exit
    };

    std::string shi_get_line();
    std::vector<std::string> shi_split_line(std::string line);
    int shi_execute(std::vector<std::string>);
    int shi_launch(std::vector<std::string>);
};

#endif // SHIMPLE_H
