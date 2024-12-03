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
    void load_from_file(const string& path);
    void save_to_file(int iteration);
    string grid_signature() const;
};
#endif