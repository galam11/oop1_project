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

    void update(const sf::Time& dt) override;
    void display(sf::RenderWindow& window) const override;

    void onKeyPressed(const sf::Event::KeyPressed& event) override;

private:
    // Menu state
    enum MenuOption { Start, Instructions, Exit, Count };
    int m_selectedIndex = 0;
    bool m_showInstructions = false;

    // UI Elements
    sf::Text m_title;
    sf::Text m_rulesText;
    std::vector<sf::Text> m_buttons;

    // Helper methods
    void updateSelection();
    void initButton(const std::string& str, float yPos);
};