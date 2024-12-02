#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <vector>
#include "cell.h"

using namespace std;

class Rule{
public:
    virtual void apply_rule(Cell cell, vector<Cell> neighbors);
};
#endif