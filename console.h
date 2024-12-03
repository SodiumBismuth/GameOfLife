#ifndef CONSOLE_H
#define CONSOLE_H

#include "grid.h"
#include "unittest.h"
#include <string>

class Console {
private:
    std::string current_path;
    int test_mode;
    int time;
    int interface;
    int iter_max;

public:
    Console();
    void select_mode();
    int get_mode();
    void select_path();
    Grid export_grid();
    UnitTest export_test();
    void select_itertime();
    int get_itertime();
    void select_interface();
    int get_interface();
    void select_iter_max();
    int get_iter_max();
};

#endif