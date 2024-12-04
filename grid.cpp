#include "grid.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>
using namespace std;

namespace fs = filesystem;

Grid::Grid(int width, int height, const string& folder_name)
    : h(height), w(width), grid(height, vector<Cell>(width)), output_folder(folder_name) {

    if (!fs::exists(output_folder)) {
        fs::create_directory(output_folder);
        cout << "Dossier créé : " << output_folder << endl;
    } else {
        cout << "Dossier existant trouvé : " << output_folder << endl;
    }
}

void Grid::update(Rule* rule) { // Mise à jour de la grille selon la règle donné
    vector<vector<Cell>> next_grid = grid; // Une nouvelle grille est crée pour éviter l'influence des cellules déjà mises à jour

    for (int i = 0; i < h; ++i) { // pour chaque cellules dans la grille
        for (int j = 0; j < w; ++j) {
            vector<Cell*> neighbors;
            for (int di = -1; di <= 1; ++di) { // Pour chaque voisins de la cellule
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if(rule->get_tor_mode()){ // si le mode torique est activé, on prend les cellules à l'opposé de la grille
                        if (ni < 0) {ni += h;} else // indice négatif ? Ajouter la largeur pour atteindre la cellule à l'opposé
                        if (ni >= h) {ni -= h;}     // indice plus grand que la largeur ? on soustrait l'indice par la largeur
                        if (nj < 0) {nj += w;} else // même chose pour la longeur
                        if (nj >= h) {nj -= w;}
                    }
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                        neighbors.push_back(&grid[ni][nj]);
                    }
                }
            }
            rule->apply_rule(&next_grid[i][j], neighbors);
        }
    }

    grid = next_grid; // on remplace la grille par la nouvelle grille
}

vector<vector<Cell>>& Grid::get_grid() {
    return grid;
}

const vector<vector<Cell>>& Grid::get_grid() const {
    return grid;
}

void Grid::load_file(const string& path) {//Ouvre le fichier choisi
    ifstream file(path);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file.");
    }

    file >> h >> w;
    grid = vector<vector<Cell>>(h, vector<Cell>(w));
    for (int i = 0; i < h; ++i) {//lecture de la grille
        for (int j = 0; j < w; ++j) {
            int state;
            file >> state;
            grid[i][j].set_state(state);
        }
    }
    file.close();
}

void Grid::save_file(int iteration) {//Enregistre les itérations dans des fichiers.txt
    ostringstream filename;
    filename << output_folder << "/Iteration_" << iteration + 1 << ".txt";

    ofstream file(filename.str());
    if (!file.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier : " + filename.str());
    }

    file << h << " " << w << "\n";
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            file << cell.get_state() << " ";
        }
        file << "\n";
    }
    file.close();

    cout << "Grille sauvegardée dans : " << filename.str() << endl;
}

string Grid::grid_arret() const {//Arret si répétition
    ostringstream arret;
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            arret << cell.get_state();
        }
        arret << "|";
    }
    return arret.str(); // retourne les états des cellules dans la grille
}

void Grid::show_grid() { // permet d'afficher la grille en mode console
    string line;
    for (const auto& row : grid) {
        line = "";
        for (const auto& cell : row) {
            string cell_repr;
            switch (cell.get_state()){
                case 0:
                    cell_repr = ". "; // mort
                break;
                case 1:
                    cell_repr = "O "; // vivant
                break;
                case 2:
                    cell_repr = "# "; // obstacle
                break;
            }
            line += cell_repr;
        }
        cout << line << endl;
    }
}
bool Grid::operator==(const Grid& other) const { // vérifier si les grilles ont les mêmes états
    const vector<vector<Cell>>& other_grid = other.get_grid();
    for (int i=0;i<h;++i) {
        for (int j=0;j<w;++j) {
            if (grid[i][j].get_state() != other_grid[i][j].get_state()){ // si les grilles ne sont pas les identiques (une cellule n'a pas le même état que l'autre)
                return false;
            }
        }
    }
    return true;
}