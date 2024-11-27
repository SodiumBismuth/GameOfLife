#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include "Grid.h"
#include "UnitTest.h"

class Console {
private:
    string current_path;
    bool test_mode;
public:
    Console()
    void select_mode()
    void select_path()
    Grid export_grid()
    UnitTEst export_test()
    void export_all_tests()
};

#endif
