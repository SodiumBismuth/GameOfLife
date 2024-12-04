#ifndef RULE_H
#define RULE_H

#include "cell.h"
#include <vector>

class Rule {
protected:
    bool tor_mode = false;
public:
    virtual void apply_rule(Cell* cell, std::vector<Cell*> neighbors) = 0;
    void switch_tor();
    bool get_tor_mode();
};

#endif