#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "AssetsManager.h"
#include "macros.h"

#include "Conntroller.h"


void test_demo();

int main()
{
	Controller controller;
	controller.run();
}



void test_demo() {
    // 1. Setup the Window (SFML 3 uses sf::VideoMode with a braced Vector2u)
    sf::RenderWindow window(sf::VideoMode({ 1300, 300 }), "SFML 3 Texture Demo");
    window.setFramerateLimit(60);

    // 2. Prepare the list of IDs from macros.h
    std::vector<char> ids = {
        PLAYER, ENEMY, COIN, FLOOR,
        BREAKABLE_FLOOR, LADDER, RAIL, EMPTY
    };

    // 3. Create Sprites
    std::vector<sf::Sprite> sprites;
    float xOffset = 30.0f;

    for (char id : ids) {
        const sf::Texture* tex = AssetsManager::instance().getTexture(id);

        if (tex) {
            sf::Sprite sprite(*tex);
            sprite.setPosition({ xOffset, 100.0f }); // SFML 3 prefers sf::Vector2f
            sprites.push_back(sprite);

            // Increment x position based on texture width
            xOffset += static_cast<float>(tex->getSize().x) + 20.0f;
        }
    }

    // 4. Main Loop (SFML 3 Event Handling)
    while (window.isOpen()) {
        // pollEvent now returns an std::optional<sf::Event>
        while (const std::optional event = window.pollEvent()) {
            // Check for specific event types using .is<T>()
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Example of handling window resize in SFML 3
            if (const auto* resized = event->getIf<sf::Event::Resized>()) {
                // Handle resize if needed
            }
        }

        window.clear(sf::Color(40, 40, 45)); // Slate background

        for (const auto& sprite : sprites) {
            window.draw(sprite);
        }

        window.display();
    }
}