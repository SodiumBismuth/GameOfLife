#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <sstream>
#include <dirent.h>
#include "grid.h"
#include "unittest.h"
#include "gui.h"

using namespace std;

class Console {
/*
Classe servant d'interface entre l'utilisateur et le programme, elle gère la sélection du chemin et traite les fichiers
donné par l'utilisateur.
*/
private:
    string current_path;
    bool test_mode;
public:
    Console() {}
    void run() {
        cout << "Simulateur Jeu de la vie" << endl;
        select_mode();
        select_path();
        if (!test_mode) {
            Grid* grid = export_grid(current_path);
            int n_iter = 0;
            GOLRule rule;
            GUI gui(grid);
    
            sf::Clock clock;
            const float timeStep = 0.5f; // Mise à jour toutes les 500ms
    
            while (gui.isOpen() && n_iter <= 100) {
                if (!gui.handleEvents()) {
                    break;
                }
    
                if (clock.getElapsedTime().asSeconds() >= timeStep) {
                    if (grid->update(&rule)) {
                        break;
                    }
                    gui.draw();
                    clock.restart();
                    n_iter++;
                }
            }
            delete grid;
        }
    }
    void select_mode() {
        cout << "Selection du mode :\n0. Normal\n1. Test" << endl;
        cin >> test_mode;
    }
    void select_path() {
        cout << "Selection du chemin\n > ";
        cin >> current_path;
    }
    Grid* export_grid(string path) {
    int w, h;
    string grid_data;
    ifstream GridFile(path);
    if (!GridFile.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier.");
    }
    
    string line;
    int n_line = 0;
    
    // Lecture de la première ligne pour les dimensions
    if (getline(GridFile, line)) {
        istringstream dim_stream(line);
        dim_stream >> w >> h;
    } else {
        throw runtime_error("Fichier vide");
    }
    
    // Lecture du reste du fichier
    while (getline(GridFile, line)) {
        grid_data += (grid_data.empty() ? "" : " ") + line;
    }
    
    GridFile.close();
    return new Grid(w, h, grid_data);
}
    UnitTest* export_test(string path) {
        int w,h;
        int n_iter = 0;
        string grid,final;
        ifstream GridFile(path);
        if (!GridFile.is_open()) {
            // erreur de lecture du fichier
            throw 3;
        }
        string line;
        int n_line = 0;
        while (getline(GridFile, line)) {
            if (!n_line){ // ligne spécifiant la longueur et la largeur de la grille
                stringstream iss(line);
                iss >> w >> h;
            } else if(n_line == 1){
                grid += line;
            } else if (n_line <= h){
                grid += " " + line;
            } else if (n_line == h+1){ // ligne spécifiant le nombre d'itérations pour atteindre la grille finale
                n_iter = stoi(line);
            } else if (n_line == h+2){
                final += line;
            } else {
                final += ' ' + line;
            }
        }
        return new UnitTest(w,h,grid,n_iter,final);
    }
    void export_all_tests() {
        DIR* dir = opendir(current_path.c_str());
        struct dirent* entity;
        int done,correct;
        while ((entity = readdir(dir)) != nullptr) {
            string filename = entity->d_name;
            UnitTest* curr_test = export_test(current_path+"/"+filename);
            if(curr_test->test()){
                correct++;
            }
            done++;
            delete curr_test;
        }
        closedir(dir);
        delete entity;
        cout << "Tout les tests sont fait (" << correct << "/" << done << ")" << endl;
    }
};

#endif
