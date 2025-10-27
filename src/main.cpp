#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Cell.hpp"

int main() {
    //Generates a random pattern of life at the start of the game eveytime
    srand(static_cast<unsigned>(time(nullptr)));

    const int width = 100;
    const int height = 80;
    const int cellSize = 10;

    std::vector<std::vector<Cell>> grid(height, std::vector<Cell>(width));

    for (auto &row : grid)
        for (auto &cell : row)
            cell.setAlive(rand() % 100 < 20);

    Game game(width, height, cellSize);


    while (game.isOpen()) {
        // Compute next state for each cell
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int liveNeighbors = 0;
                for (int dy = -1; dy <= 1; ++dy) {
                    for (int dx = -1; dx <= 1; ++dx) {
                        if (dx == 0 && dy == 0) continue;
                        int ny = (y + dy + height) % height;
                        int nx = (x + dx + width) % width;
                        if (grid[ny][nx].isAlive())
                            liveNeighbors++;
                    }
                }
                grid[y][x].computeNextState(liveNeighbors);
            }
        }

        for (auto &row : grid)
            for (auto &cell : row)
                cell.update();


        game.render(grid);
    }

    return 0;
}
