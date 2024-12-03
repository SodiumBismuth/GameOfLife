#include "console.h"
#include <iostream>
#include <string>
using namespace std;

Console::Console() : test_mode(0) {}

void Console::select_mode() {
    cout << "Select mode (1: Simulation, 2: Unit Test): ";
    int choice;
    cin >> choice;
    test_mode = choice;
}

int Console::get_mode() {
    return test_mode;
}

void Console::select_path() {
        cout << "Enter file path: ";
        cin >> current_path;
    }

Grid Console::export_grid() {
        Grid grid(0, 0, "output_grids");
        grid.load_file(current_path);
        return grid;
    }

UnitTest Console::export_test() {
    string result_path;
    int n_iter;
    cout << "Enter result path: ";
    cin >> result_path;
    cout << "Nombre d'itérations pour atteindre le résultat: ";
    cin >> n_iter;
    UnitTest test(0,0,current_path,result_path,n_iter);
    return test;
}
void Console::select_itertime() {
    cout << "Temps entre chaque itérations (en ms): ";
    cin >> time;
}

int Console::get_itertime() {
    return time;
}

void Console::select_interface() {
    cout << "Choix de l'interface (1: Graphique, 2: Console): ";
    cin >> interface;
}

int Console::get_interface() {
    return interface;
}

void Console::select_iter_max() {
    cout << "Choix du nombre maximum d'itérations: ";
    cin >> iter_max;
}
int Console::get_iter_max(){
    return iter_max;
}