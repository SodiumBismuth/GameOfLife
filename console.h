#ifndef CONSOLE_H
#define CONSOLE_H

#include "grid.h"
#include <string>

class Console {
private:
    std::string current_path;
    bool test_mode;

public:
    Console();
    void select_mode();
    void select_path();
    Grid export_grid();
};

#endif