#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "AssetsManager.h"
#include "macros.h"

void test_demo();

int main()
{
    test_demo();
    std::cout << "Done" << std::endl;
}

void test_demo() {
    // 1. Setup Context Settings to help with driver detection
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0; // Disable to reduce load on software driver

    // 2. Create Window
    sf::RenderWindow window(sf::VideoMode(800, 300), "SFML Assets Demo", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    // 3. Define the IDs to display
    std::vector<char> ids = {
        PLAYER, ENEMY, COIN, FLOOR,
        BREAKABLE_FLOOR, LADDER, RAIL, EMPTY
    };

    // 4. Create Sprites
    std::vector<sf::Sprite> sprites;
    float xPos = 50.0f;
    float yPos = 100.0f;

    for (char id : ids) {
        const sf::Texture* tex = AssetsManager::instance().getTexture(id);

        if (tex != nullptr) {
            sf::Sprite sprite(*tex);
            sprite.setPosition(xPos, yPos);

            // Fix for "texture_edge_clamp" warning: 
            // This prevents artifacts on the edges of your sprites
            const_cast<sf::Texture*>(tex)->setSmooth(false);

            sprites.push_back(sprite);
            xPos += tex->getSize().x + 25.0f; // Space them out
        }
    }

    // 5. App Loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(30, 30, 30)); // Dark background

        for (const auto& s : sprites) {
            window.draw(s);
        }

        window.display();
    }
}
