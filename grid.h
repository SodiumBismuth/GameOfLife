#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "cell.h"
#include "golrule.h"

using namespace std;

class Grid{
private:
    vector<vector<Cell*>> grid;
    int h, w;
public:
    Grid(int w, int h, string grid_data) : w(w), h(h){//construteur
        vector<vector<Cell*>> grid(h, vector<Cell*>(w, nullptr));

    // Utiliser un istringstream pour lire les données
        istringstream iss(grid_data);
        int value;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (iss >> value) {
                    // Créer une nouvelle Cell et définir son état
                    grid[i][j] = new Cell();
                    grid[i][j]->set_state(value);
                } else {
                    throw 4;
                }
            }
        }
    }  

    void update(Rule* rule) {}//change le statut de la cellule
    
    vector<vector<Cell*>>get_grid(); //retourne le statut de la cellule

};

#endif