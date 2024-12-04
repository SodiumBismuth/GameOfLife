#include "golrule.h"

void GOLRule::apply_rule(Cell* cell, std::vector<Cell*> neighbors) {
    int alive_count = 0; //Nombre de voisin vivant
    for (auto neighbor : neighbors) {// auto : détecte le type
        if (neighbor->get_state() == 1) {
            ++alive_count;
        }
    }

    if (cell->get_state() == 1) {
        if (alive_count < 2 || alive_count > 3) {
            cell->set_state(0); // La cellule meurt
        }
    } else if (cell->get_state() == 0) {
        if (alive_count == 3) {
            cell->set_state(1); // La cellule devient vivante
        }
    }
}