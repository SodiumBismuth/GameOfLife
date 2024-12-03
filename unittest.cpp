#include <iostream>
#include <string>
#include "unittest.h"
using namespace std;

    UnitTest::UnitTest(int w, int h, const string& initial) : iterations(0), grid(w, h, "output_grids"), result(w, h, "output_grids") {
        grid.load_from_file(initial);
    }

    bool UnitTest::test() {
        // Implémentation simplifiée
        return true;
    }