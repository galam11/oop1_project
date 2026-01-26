#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <vector>
#include <string>
#include <SFML/Audio.hpp>

class EndScreenScene : public Scene
{
public:
    EndScreenScene(bool victory, int score);
    virtual ~EndScreenScene() = default;

    void update(const sf::Time& dt) override;
    void display(sf::RenderWindow& window) const override;

    void onKeyPressed(const sf::Event::KeyPressed& event) override;

private:
    enum MenuOption { Restart, MainMenu, Exit, Count };
    int m_selectedIndex = 0;

    sf::Text m_statusText;
    sf::Text m_scoreText;
    std::vector<sf::Text> m_buttons;

    void updateSelection();
    void initButton(const std::string& str, float yPos);
};