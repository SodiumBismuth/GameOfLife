#ifndef UNITTEST_H
#define UNITTEST_H

#include "grid.h"

class UnitTest {
private:
    int iterations;
    Grid grid;
    Grid result;

public:
    UnitTest(int w, int h, const std::string& initial, const std::string& result, int iterations);
    bool test(Rule* rule);
};

#endif