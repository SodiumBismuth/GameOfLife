#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "grid.h"

class GUI {
private:
    Grid* grid;
    sf::RenderWindow window;
    const int cellSize = 50;

public:
    GUI(Grid* grid) : grid(grid) {
        if (!grid || grid->get_w() <= 0 || grid->get_h() <= 0) {
            throw std::runtime_error("Invalid grid dimensions");
        }
        window.create(sf::VideoMode(grid->get_w() * cellSize, grid->get_h() * cellSize), "Game of Life");
    }

    bool isOpen() const {
        return window.isOpen();
    }

    bool handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
        }
        return true;
    }

    void draw() {
        window.clear(sf::Color::Black);  // Fond noir
        sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
        cell.setFillColor(sf::Color::White);  // Cellules blanches

        for (int x = 0; x < grid->get_w(); ++x) {
            for (int y = 0; y < grid->get_h(); ++y) {
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
