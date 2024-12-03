#include "gui.h"

GUI::GUI(Grid* g) : grid(g), window(sf::VideoMode(800, 600), "Jeu de la Vie"), palette({sf::Color::Black, sf::Color::Green}) {}

void GUI::draw() {
    const int cell_size = 20;
    window.clear();
    auto& cells = grid->get_grid();
    for (int i = 0; i < cells.size(); ++i) {
        for (int j = 0; j < cells[i].size(); ++j) {
            sf::RectangleShape cell_shape(sf::Vector2f(cell_size - 1, cell_size - 1));
            cell_shape.setPosition(j * cell_size, i * cell_size);
            cell_shape.setFillColor(palette[cells[i][j].get_state()]);
            window.draw(cell_shape);
        }
    }
    window.display();
}

sf::RenderWindow& GUI::get_window() {
    return window;
}