#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell{
private:
    int state; //mort ou vivant
public:
    Cell() {} //construteur

    void set_state(int new_state) {state = new_state;}//change le statut de la cellule
    
    int get_state() {return state;} //retourne le statut de la cellule

};

#endif