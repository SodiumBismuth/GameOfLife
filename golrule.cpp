#include "golrule.h"

void GOLRule::apply_rule(Cell* cell, std::vector<Cell*> neighbors) {
    int alive_count = 0;
    for (auto neighbor : neighbors) {
        if (neighbor->get_state() == 1) {
            ++alive_count;
        }
    }

    if (cell->get_state() == 1) {
        if (alive_count < 2 || alive_count > 3) {
            cell->set_state(0); // La cellule meurt
        }
    } else {
        if (alive_count == 3) {
            cell->set_state(1); // La cellule devient vivante
        }
    }
}