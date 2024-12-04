#include "rule.h"
#include <iostream>
#include <vector>

using namespace std;

void Rule::apply_rule(Cell* cell, vector<Cell*> neighbors) {} // aplique une règle sur une cellule

void Rule::switch_tor() { // active / désactive le mode torique
    tor_mode = (tor_mode ? false : true);
}

bool Rule::get_tor_mode() {
    return tor_mode;
}