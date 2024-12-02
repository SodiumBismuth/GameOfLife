#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell{
private:
    int state; //mort ou vivant
public:
    Cell() {} //construteur

    bool operator==(const Cell& other) const {
        return state == other.get_state();
    }

    void set_state(int new_state) {state = new_state;}//change le statut de la cellule
    
    int get_state() const {return state;} //retourne le statut de la cellule

};

#endif