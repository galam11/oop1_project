#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <vector>
#include <string>

class MainMenuScene : public Scene
{
public:
    MainMenuScene();
    virtual ~MainMenuScene() = default;

    void display(sf::RenderWindow& window) const override;
    void update(const sf::Time& dt) override;
    void onKeyPressed(const sf::Event::KeyPressed& event) override;

private:
    enum MenuOption { Start, Instructions, Exit, Count };
    int m_selectedIndex = 0;
    bool m_showInstructions = false;

    sf::Text m_title;
    sf::Text m_rulesText;
    std::vector<sf::Text> m_buttons;

    void updateSelection();
    void initButton(const std::string& str, float yPos);
};