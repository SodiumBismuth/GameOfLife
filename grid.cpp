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

void Grid::update(Rule* rule) {
    vector<vector<Cell>> next_grid = grid;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            vector<Cell*> neighbors;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                        neighbors.push_back(&grid[ni][nj]);
                    }
                }
            }
            rule->apply_rule(&next_grid[i][j], neighbors);
        }
    }

    grid = next_grid;
}

vector<vector<Cell>>& Grid::get_grid() {
    return grid;
}

void Grid::load_from_file(const string& path) {
    ifstream file(path);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file.");
    }

    file >> h >> w;
    grid = vector<vector<Cell>>(h, vector<Cell>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int state;
            file >> state;
            grid[i][j].set_state(state);
        }
    }
    file.close();
}

void Grid::save_to_file(int iteration) {
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

string Grid::grid_signature() const {
    ostringstream signature;
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            signature << cell.get_state();
        }
        signature << "|";
    }
    return signature.str();
}