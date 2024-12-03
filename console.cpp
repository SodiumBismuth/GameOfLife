#include "console.h"
#include <iostream>

Console::Console() : test_mode(false) {}

void Console::select_mode() {
    std::cout << "Select mode (1: Simulation, 2: Unit Test): ";
    int choice;
    std::cin >> choice;
    test_mode = (choice == 2);
}
void Console::select_path() {
        std::cout << "Enter file path: ";
        std::cin >> current_path;
    }

Grid Console::export_grid() {
        Grid grid(0, 0, "output_grids");
        grid.load_from_file(current_path);
        return grid;
    }
