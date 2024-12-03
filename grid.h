#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include "rule.h"
#include <vector>
#include <string>
using namespace std;

class Grid {
private:
    int h, w;
    vector<vector<Cell>> grid;
    string output_folder;

public:
    Grid(int width, int height, const string& folder_name);
    void update(Rule* rule);
    vector<vector<Cell>>& get_grid();
    const vector<vector<Cell>>& get_grid() const;
    void load_file(const string& path);
    void save_file(int iteration);
    string grid_arret() const;
    void show_grid();
    bool operator==(const Grid& other) const;
};
#endif