#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "grid.h"

using namespace std;

class GUI{
private:
    Grid* grid;
    sf::RenderWindow window;
    vector<sf::Color> palete;
public:
    GUI(Grid* grid) : grid(grid) {} //construteur

    void draw() {
        const int cellSize = 10;
        int x,y;    
        window.clear();
        sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f)); 
        for (x = 0; x < grid->get_w(); ++x) { //longueur de la grille
            for (y = 0; y < grid->get_h(); ++y) { // hauteur de la grille
                if (grid->get_grid()[x][y].get_state() == 1) {
                    cell.setPosition(x * cellSize, y * cellSize);
                    window.draw(cell);
                }
            }
        }
        window.display();
    }
};

#endif