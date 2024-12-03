#include "console.h"
#include "grid.h"
#include "golrule.h"
#include "gui.h"
#include <unordered_map>
#include <iostream>
#include <SFML/System.hpp>

int main(int argc, char* argv[]) {
    Console console;
    console.select_mode();
    console.select_path();

    Grid grid = console.export_grid();
    GOLRule rule;
    GUI gui(&grid);

    int iteration = 0;
    std::unordered_map<std::string, int> previous_signatures;

    while (gui.get_window().isOpen()) {
        sf::Event event;
        while (gui.get_window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gui.get_window().close();
            }
        }

        grid.save_to_file(iteration);

        std::string signature = grid.grid_signature();
        if (previous_signatures[signature] == 4) {
            std::cout << "Condition d'arrêt : cycle détecté." << std::endl;
            break;
        }
        previous_signatures[signature]++;

        gui.draw();

        grid.update(&rule);
        sf::sleep(sf::milliseconds(500));

        iteration++;
    }

    return 0;
}