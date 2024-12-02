#ifndef UNITTEST_H
#define UNITTEST_H

#include <iostream>
#include <string>

class UnitTest{
private:
    int iterations;
    Grid* grid;
    Grid* result;
public:
    UnitTest(int w, int h, string initial, int n_iter, string final) : iterations(n_iter) {
        grid = new Grid(w,h,initial);
        result = new Grid(w,h,final);
    }
    bool test() {
        return true;
    }
};
#endif