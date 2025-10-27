#include "Game.hpp"

Game::Game(int w, int h, int c)
    : width(w), height(h), cellSize(c),
      window(sf::VideoMode(w * c, h * c), "Game of Life") 
    {
        window.setFramerateLimit(30); 
    }

bool Game::isOpen() const {
    return window.isOpen();
}

void Game::render(const std::vector<std::vector<Cell>>& grid) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // Background gradient effect
    sf::RectangleShape background(sf::Vector2f(width * cellSize, height * cellSize));
    sf::Color topColor(10, 10, 25);     // dark navy blue
    sf::Color bottomColor(25, 10, 40);  // deep purple tint
    background.setFillColor(bottomColor);
    window.clear();
    window.draw(background);

    // Glow effect overlay (semi-transparent light pulse)
    static float glowTimer = 0.0f;
    glowTimer += 0.05f;
    float glowIntensity = (std::sin(glowTimer) + 1.0f) * 0.3f; // smooth pulse between 0–0.6
    sf::Color glowColor(100, 100, 255, static_cast<sf::Uint8>(60 * glowIntensity));

    sf::RectangleShape glow(sf::Vector2f(width * cellSize, height * cellSize));
    glow.setFillColor(glowColor);
    window.draw(glow, sf::BlendAdd);  // additive blending for glow

    // Draw cells
    sf::RectangleShape cellShape(sf::Vector2f(cellSize - 1, cellSize - 1));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (grid[y][x].isAlive()) {
                // color shifts slowly over time
                float time = glowTimer * 10.f;
                sf::Uint8 r = static_cast<sf::Uint8>(120 + 80 * std::sin(time + x * 0.1f));
                sf::Uint8 g = static_cast<sf::Uint8>(120 + 80 * std::sin(time + y * 0.1f));
                sf::Uint8 b = 255;

                cellShape.setFillColor(sf::Color(r, g, b));
                cellShape.setPosition(x * cellSize, y * cellSize);
                window.draw(cellShape);
            }
        }
    }

    // Subtle vignette (dark edges)
    sf::RectangleShape vignette(sf::Vector2f(width * cellSize, height * cellSize));
    vignette.setFillColor(sf::Color(0, 0, 0, 50));
    window.draw(vignette);

    window.display();
}

