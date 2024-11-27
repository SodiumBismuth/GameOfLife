#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include "grid.h"
#include "unittest.h"

using namespace std;

class Console {
private:
    string current_path;
    bool test_mode;
public:
    Console()
    void select_mode()
    void select_path()
    Grid export_grid()
    UnitTest export_test()
    void export_all_tests()
};

#endif
