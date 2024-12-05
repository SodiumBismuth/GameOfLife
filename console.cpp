#include "console.h"
#include <iostream>
#include <string>
using namespace std;

Console::Console() : test_mode(0) {}

void Console::select_mode() { //Fonction pour le choix du mode
    cout << "Sélection du mode (1: Simulation, 2: Test Unitaire): ";
    int choice;
    cin >> choice;
    test_mode = choice;
}

int Console::get_mode() { // Retourne le mode
    return test_mode;
}

void Console::select_path() { //Demande le chemin du fichier
        cout << "Entre le chemin du fichier: ";
        cin >> current_path;
    }

Grid Console::export_grid() { //Transforme un fichier en objet grille
        Grid grid(0, 0, current_path.substr(0, current_path.length() - 4)+"_out");
        grid.load_file(current_path);
        return grid;
    }

UnitTest Console::export_test() {//Fonction pour chemin du fichier de sortie et le nombre itération du résultat 
    string result_path;
    int n_iter;
    cout << "Entre le chemin du fichier résultat: ";
    cin >> result_path;
    cout << "Nombre d'itérations pour atteindre le résultat: ";
    cin >> n_iter;
    UnitTest test(0,0,current_path,result_path,n_iter);
    return test;
}
void Console::select_itertime() {//Définition du temps entre 2 grille
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