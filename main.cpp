#include "console.h"
#include "grid.h"
#include "golrule.h"
#include "gui.h"
#include "unittest.h"
#include <unordered_map>
#include <iostream>
#include <SFML/System.hpp>
using namespace std; 

int main(int argc, char* argv[]) {
    srand (time(NULL));
    Console console;
    console.select_mode();
    console.select_path();
    switch (console.get_mode()){ // 1: Mode normal | 2: Mode test
        case 1: {
            console.select_itertime();//Définition des différents paramètres
            console.select_interface();
            console.select_iter_max();
            
            int iteration = 0;
            int iter_max = console.get_iter_max();
            unordered_map<string, int> previous_grid; // stocke le nombre de fois qu'un certain état de la grille est vu
            
            GOLRule rule;
            rule.switch_tor(); // Commenter cette ligne pour désactiver la grille torique
            
            Grid grid = console.export_grid(); // initialisation de la grille
            
        if(console.get_interface()==1){//graphique
            GUI gui(&grid); // initialisation de l'intrface

            while (gui.get_window().isOpen() && iteration < iter_max) {
                sf::Event event;

                while (gui.get_window().pollEvent(event)) { // gère la fermeture de la fenêtre
                    if (event.type == sf::Event::Closed) {
                        gui.get_window().close();
                    }
                }

                string arret = grid.grid_arret(); //Arrete le programme si repetition 
                if (previous_grid[arret] == 10) {
                    cout << "Condition d'arrêt : cycle détecté." << endl;
                    break;
                }

                previous_grid[arret]++;
                gui.draw();
                grid.update(&rule);
                sf::sleep(sf::milliseconds(console.get_itertime())); // Temps de pause entre deux itérations
                iteration++;
            }

        } else { // console
            while(iteration < iter_max){  // Arrete le programme si iteration est plus grand que iteration maximum
                grid.save_file(iteration);
                grid.show_grid();

                string arret = grid.grid_arret();
                if (previous_grid[arret] == 4) {
                    cout << "Condition d'arrêt : cycle détecté." << endl;
                    break;
                }

                previous_grid[arret]++;
                grid.update(&rule);
                sf::sleep(sf::milliseconds(console.get_itertime()));
                iteration++;
            }
        }   
    }
    break;
    case 2: {
        UnitTest test = console.export_test(); //Mode Test unitaire
        GOLRule rule;
        if (test.test(&rule)){
            cout << "Test Réussi !" << endl;
        } else {
            cout << "Test Raté !" << endl;
        }
    }
    break;
    }
    return 0;
}