#include "LevelScene.h"
#include <iostream>

LevelScene::LevelScene()
{
    loadLevel();
}

LevelScene::~LevelScene()
{
    for (auto* obj : m_movableGameObjects)
        delete obj;
    m_movableGameObjects.clear();
}

void LevelScene::loadLevel()
{
    clearLevel();

    sf::Vector2f boardSize;

    if (!m_board.loadNextLevel(m_gameObjects, m_movableGameObjects, boardSize))
    {
        std::cout << "Game Over or No More Levels!" << std::endl;
        return;
    }

    m_view.setSize(boardSize);
    m_view.setCenter({ boardSize.x / 2.f, boardSize.y / 2.f });
}

void LevelScene::update(const sf::Time& dt)
{
    for (auto* obj : m_movableGameObjects)
    {
        obj->update();
        obj->updatePositon(dt);
    }
}

void LevelScene::display(sf::RenderWindow& window) const
{
    window.setView(m_view);

    Scene::display(window);

    for (const auto& gameObject : m_movableGameObjects)
        gameObject->draw(window);

    window.setView(window.getDefaultView());
    // render menus
}

void LevelScene::clearLevel()
{
    for (auto* obj : m_movableGameObjects) 
        delete obj;
    m_movableGameObjects.clear();

    for (auto* obj : m_gameObjects) 
        delete obj;
    m_gameObjects.clear();
}


// for debuge
void LevelScene::onKeyReleased(const sf::Event::KeyReleased& event)
{
    if (event.code == sf::Keyboard::Key::Space)
        loadLevel();
}