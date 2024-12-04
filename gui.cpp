#include "gui.h"

GUI::GUI(Grid* g) : grid(g), window(sf::VideoMode(800, 600), "Jeu de la Vie"), palette({sf::Color::Black, sf::Color::Green, sf::Color::Red}) {} //Parametre de la fenetre

void GUI::draw() {
    const int cell_size = 20;
    window.clear();//renitialisation de la grille
    auto& cells = grid->get_grid();
    for (int i = 0; i < cells.size(); ++i) {//longueur de la grille
        for (int j = 0; j < cells[i].size(); ++j) { //largueur de la grille
            sf::RectangleShape cell_shape(sf::Vector2f(cell_size - 1, cell_size - 1));//Carre représentant la cellule
            cell_shape.setPosition(j * cell_size, i * cell_size);//Coordonnées de la cellule
            cell_shape.setFillColor(palette[cells[i][j].get_state()]);//couleur dans la grille
            window.draw(cell_shape);
        }
    }
    window.display();//affiche le résultat à l'écran
}

sf::RenderWindow& GUI::get_window() {//retourne la grille
    return window;
}