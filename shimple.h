#ifndef SHIMPLE_H
#define SHIMPLE_H

#include <string>
#include <vector>

class Shimple {
public:
    Shimple();
    void shi_loop();

private:
    std::string shi_get_line();
    std::vector<std::string> shi_split_line(std::string line);
};

#endif // SHIMPLE_H
