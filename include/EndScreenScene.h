#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <vector>
#include <string>

class EndScreenScene : public Scene
{
public:
    // Takes whether the player won and their final score
    EndScreenScene(bool victory, int score);
    virtual ~EndScreenScene() = default;

    void update(const sf::Time& dt) override;
    void display(sf::RenderWindow& window) const override;

    // SFML 3.0 Keyboard handler
    void onKeyPressed(const sf::Event::KeyPressed& event) override;

private:
    enum MenuOption { Restart, MainMenu, Exit, Count };
    int m_selectedIndex = 0;

    // SFML 3.0: These require a font at construction
    sf::Text m_statusText;
    sf::Text m_scoreText;
    std::vector<sf::Text> m_buttons;

    void updateSelection();
    void initButton(const std::string& str, float yPos);
};