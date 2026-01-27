#pragma once
#include "MenuScene.h"
#include <SFML/Graphics.hpp>
#include <string>

class EndScreenScene : public MenuScene
{
public:
    EndScreenScene(bool victory, int score);

    void display(sf::RenderWindow& window) const override;
    void onKeyPressed(const sf::Event::KeyPressed& event) override;

private:
    enum MenuOption { Restart, MainMenu, Exit, Count };

    sf::Text m_statusText;
    sf::Text m_scoreText;
};