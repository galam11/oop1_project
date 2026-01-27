#pragma once
#include "Scene.h"
#include "Board.h"
#include "Hud.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class LevelScene : public Scene
{
public:
    LevelScene();

    void update(const sf::Time& dt) override;
    void display(sf::RenderWindow& window) const override;

private:
    Hud m_hud;
    sf::Clock m_timer;

    void nextLevel();
    void hardResetLevel();
    void softResetLevel();
};