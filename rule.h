#ifndef RULE_H
#define RULE_H

#include "cell.h"
#include <vector>

class Rule {
public:
    virtual void apply_rule(Cell* cell, std::vector<Cell*> neighbors) = 0;
};

#endif