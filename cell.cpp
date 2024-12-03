#include "cell.h"

Cell::Cell() : state(0) {}

void Cell::set_state(int s) {
    state = s;
}

int Cell::get_state() const {
    return state;
}