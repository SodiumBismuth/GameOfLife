#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "cell.h"
#include "golrule.h"

using namespace std;

class Grid{ //classe permettant de réaliser une grille avec des cellules
private:
    int w, h;
    vector<vector<Cell>> grid;
    string output_folder;
public:
    Grid(int width, int height, string grid_data) : w(width), h(height) {
        // Créer la grille avec w colonnes et h lignes
        grid = vector<vector<Cell>>(w, vector<Cell>(h));

        istringstream iss(grid_data);
        string value;

        // Noter l'inversion des boucles pour correspondre au format du fichier
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (iss >> value) {
                    grid[x][y].set_state(stoi(value));
                } else {
                    throw std::runtime_error("Données de grille invalides");
                }
            }
        }
    }  

    bool update(Rule* rule){ //change le statut de la cellule
        vector<vector<Cell>>next_grid = grid; //Permet de mettre a jour l'etat de toutes les cellules sans prendre celles deja mise à jour
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

    int get_w() {return w;}
    int get_h() {return h;}

    void load_file(const std::string& path) { // verifie
        std::ifstream file(path);
        if (!file.is_open()) {
            throw std::runtime_error("Impossible d'ouvrir le fichier.");
        }

        file >> h >> w;
        grid = std::vector<std::vector<Cell>>(h, std::vector<Cell>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int state;
                file >> state;
                grid[i][j].set_state(state);
            }
        }
        file.close();
    }
    void save_file(int iteration){
        ostringstream filename;
        filename << output_folder << "/Itération " << iteration << ".txt";
        ofstream file(filename.str());
        if(!file.is_open()){
            cout << "Impossible d'ouvrir le fichier suivant : " << filename.str();
        }
        file << h << " " << w << "\n";
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                file << cell.get_state() << " ";
            }
            file << "\n";
        }
        file.close();
        cout << "Grille sauvegardee dans le fichier : " << filename.str() << endl;
    }
};

#endif