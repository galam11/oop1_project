#pragma once
#include "Scene.h"
#include "Board.h"
#include "Player.h"
#include <vector>
#include <SFML/Graphics.hpp>

class LevelScene : public Scene
{
public:
    LevelScene();
    ~LevelScene() override;

    void update(const sf::Time& dt) override;
    void display(sf::RenderWindow& window) const override;
    void onKeyPressed(const sf::Event::KeyPressed& event) override;
    void onKeyReleased(const sf::Event::KeyReleased& event) override;

private:
    Board m_board;
    std::vector<MovableGameObject*> m_movableGameObjects;

    sf::View m_view;

    void loadLevel();
    void clearLevel();
};