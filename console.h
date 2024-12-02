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
    Console() {
        cout << "Simulateur Jeu de la vie" << endl;
        select_mode();
        select_path();
        if (test_mode) {
        /*
        [MODE DE TEST]
        */
            // Sélection du traitement selon si le chemin est un fichier ou un dossier
            struct stat s;
            if(stat(current_path.c_str(),&s) == 0 ) {
                if( s.st_mode & S_IFDIR ) {
                    export_all_tests();
                } else if( s.st_mode & S_IFREG ) {
                    UnitTest* test = export_test(current_path);
                    test->test();
                } else {
                    // Pas un fichier ni un dossier
                    throw 1;
                }
            } else {
                // Erreur
                throw 2;
            }
        } else {
            /*
            [MODE NORMAL]
            */
            Grid* grid = export_grid(current_path);
            int n_iter;
            GOLRule* rule = new GOLRule();
            GUI gui(grid);
            while(!grid->update(rule) && n_iter <= 100) {
                gui.draw();
            }
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
        int w,h;
        string grid;
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
            } else {
                grid += " " + line;
            }
        }
        return new Grid(w,h,grid);
    }
    UnitTest* export_test(string path) {
        int w,h,n_iter;
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
        }
        cout << "Tout les tests sont fait (" << correct << "/" << done << ")" << endl;
    }
};

#endif
