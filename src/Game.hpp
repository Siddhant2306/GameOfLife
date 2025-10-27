#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.hpp"

class Game {
private:
    sf::RenderWindow window;
    int width, height, cellSize;

public:
    Game(int w, int h, int c);
    bool isOpen() const;
    void render(const std::vector<std::vector<Cell>>& grid);
};
