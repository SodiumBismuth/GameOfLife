#ifndef GOLRULE_H
#define GOLRULE_H

#include <iostream>
#include <vector>
#include "rule.h"
using namespace std;

class GOLRule : public Rule {
public:
    void apply_rule(Cell* cell, vector<Cell*> neighbors) override{ //Applique la règle basique de gol
        int alive_count=0; //Compteur de cellule vivante
        for(Cell* neighbor : neighbors){ //boucle pour regarder l'état des voisins
            if (neighbor->get_state() == 1)
             ++alive_count;
        }
        if(cell->get_state() == 1){ 
            if(alive_count < 2 || alive_count > 3 ){ //cellule vivante devient morte
                cell->set_state(0);
            } else {
                cell->set_state(1); //cellule vivante reste vivante
            }
        }
        else{ 
            if(alive_count ==3){
                cell->set_state(1); //cellule morte devient vivante
            }
        }
    } 
};

#endif