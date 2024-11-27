#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>

class Grid{
private:
    vector<vector<Cell*>> grid;
    int h;
    int w;
public:
    Grid(int w, int h, string grid) //construteur

    void update(Rule* rule) {}//change le statut de la cellule
    
    vector<vector<Cell*>>get_grid() //retourne le statut de la cellule

};

#endif