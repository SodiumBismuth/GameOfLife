#ifndef GOLRULE_H
#define GOLRULE_H

#include "rule.h"

class GOLRule : public Rule {
public:
    void apply_rule(Cell* cell, std::vector<Cell*> neighbors) override;
};

#endif