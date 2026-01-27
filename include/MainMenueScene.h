#pragma once
#include "MenuScene.h"
#include <SFML/Graphics.hpp>
#include <string>

class MainMenuScene : public MenuScene
{
public:
    MainMenuScene();
    virtual ~MainMenuScene() = default;

    void display(sf::RenderWindow& window) const override;
    void onKeyPressed(const sf::Event::KeyPressed& event) override;

private:
    enum MenuOption { Start, Instructions, Exit, Count };
    bool m_showInstructions = false;

    sf::Text m_title;
    sf::Text m_rulesText;
};