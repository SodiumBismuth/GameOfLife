#include "cell.h"

Cell::Cell() : state(0) {}

void Cell::set_state(int s) {//definit le statut de la cellule
    state = s;
}

int Cell::get_state() const {//Retourne le statut de la cellule
    return state;
}