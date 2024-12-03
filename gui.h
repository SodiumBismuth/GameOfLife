#ifndef GUI_H
#define GUI_H

#include "grid.h"
#include <SFML/Graphics.hpp>

class GUI {
private:
    Grid* grid;
    sf::RenderWindow window;
    std::vector<sf::Color> palette;

public:
    GUI(Grid* g);
    void draw();
    sf::RenderWindow& get_window();
};

#endif