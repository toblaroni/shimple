#ifndef SHIMPLE_H
#define SHIMPLE_H

#define SHI_EXIT_BAD_EXECUTION -1
#define SHI_EXIT_BAD_INPUT     -2

#include <string.h>
#include <vector>

class Shimple {

public:
    Shimple();
    void shi_start();

private:
    // Programs that are built into the shell
    std::vector<std::string> buildin_str = {
        "cd",
        "help",
        "exit"
    };

    std::string shi_get_line();
    std::vector<std::string> shi_split_line(std::string line);
    int shi_execute(std::vector<std::string>);
    int shi_launch(std::vector<std::string>);
};

#endif // SHIMPLE_H
