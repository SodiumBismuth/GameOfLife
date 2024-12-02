#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "cell.h"
#include "golrule.h"

using namespace std;

class Grid{ //classe permettant de réaliser une grille avec des cellules
private:
    vector<vector<Cell>> grid;
    int h, w;
public:
    Grid(int w, int h, string grid_data) : w(w), h(h){//construteur
        vector<vector<Cell>> grid(h, vector<Cell>(w));

    // Utiliser un istringstream pour lire les données
        istringstream iss(grid_data);
        int value;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (iss >> value) {
                    // Créer une nouvelle Cell et définir son état
                    grid[i][j] = Cell();
                    grid[i][j].set_state(value);
                } else {
                    throw 4;
                }
            }
        }
    }  

    bool update(Rule* rule){ //change le statut de la cellule
        vector<vector<Cell>>next_grid = grid; 
    //Permet de mettre a jour l'état de toutes les cellules sans prendre celles déjà mise à jour
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){ // Parcours toutes les cellules
                vector<Cell> neighbors;
                for (int di = -1; di <=1; di++){ // regarde chaque voisin
                    for (int dj = -1; dj<=1; dj++){
                        if (di == 0 && dj == 0) continue; // evite la cellule
                        int ni = i + di, nj = j +dj;
                        if (ni >=0 && ni < h && nj >= 0 && nj < w){
                            neighbors.push_back(grid[ni][nj]);
                        }
                    }
                }
                rule->apply_rule(next_grid[i][j], neighbors); // applique les regles
            }
        }
        grid = next_grid; // Mise a jour de la grille
        return grid == next_grid;
    }
    vector<vector<Cell>>get_grid() {return grid;} ; //retourne la grille

    void save_file();
};

#endif