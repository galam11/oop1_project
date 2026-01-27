#pragma once
#include "Scene.h"
#include <vector>
#include <string>

class MenuScene : public Scene
{
public:
    MenuScene(const std::string& boardFilePath, SoundID soundId);
    virtual ~MenuScene() = default;

    virtual void update(const sf::Time& dt) override;

    virtual void onKeyPressed(const sf::Event::KeyPressed& event) override;

protected:
    std::vector<sf::Text> m_buttons;
    int m_selectedIndex = 0;

    void initButton(const std::string& str, float yPos, int fontSize);

    void updateSelection();

    void drawButtons(sf::RenderWindow& window) const;
};