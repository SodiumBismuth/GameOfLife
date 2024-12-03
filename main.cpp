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
    Console console;
    console.select_mode();
    console.select_path();
    switch (console.get_mode()){
        case 1: {
            console.select_itertime();
            console.select_interface();
            console.select_iter_max();
            GOLRule rule;
            Grid grid = console.export_grid();
            int iteration = 0;
            int iter_max = console.get_iter_max();
            unordered_map<string, int> previous_grid;
            
        if(console.get_interface()==1){//graphique
            GUI gui(&grid);
            while (gui.get_window().isOpen() && iteration < iter_max) {
                sf::Event event;
                while (gui.get_window().pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        gui.get_window().close();
                    }
                }

                string arret = grid.grid_arret();
                if (previous_grid[arret] == 4) {
                    cout << "Condition d'arrêt : cycle détecté." << endl;
                    break;
                }
                previous_grid[arret]++;

                gui.draw();

                grid.update(&rule);
                sf::sleep(sf::milliseconds(console.get_itertime()));

                iteration++;
            }
        } else { // console
            while(iteration < iter_max){
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
        
    case 2:
    {
        UnitTest test = console.export_test();
        GOLRule rule;
        if (test.test(&rule)){
            cout << "Test Réussi !" << endl;
        } else {
            cout << "Test Raté :(" << endl;
        }
        }
        break;
    }
        return 0;
}