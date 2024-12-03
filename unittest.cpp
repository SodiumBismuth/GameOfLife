#include <iostream>
#include <string>
#include "unittest.h"
using namespace std;

    UnitTest::UnitTest(int w, int h, const string& initial, const string& final, int iterations) : iterations(iterations), grid(w, h, "output_grids"), result(w, h, "output_grids") {
        grid.load_file(initial);
        result.load_file(final);
    }

    bool UnitTest::test(Rule* rule) {
        int i;
        for(i=0;i!=iterations-1;++i){
            grid.update(rule);
        }
        return grid == result;
    }