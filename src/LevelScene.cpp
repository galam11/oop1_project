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

    // FIXED: Must be sf::Vector2f to match Board.h and m_view.setSize()
    sf::Vector2f boardSize;

    // This call will now match the signature in Board.h
    if (!m_board.loadNextLevel(m_gameObjects, m_movableGameObjects, boardSize))
    {
        std::cout << "Game Over or No More Levels!" << std::endl;
        return;
    }

    // --- FIT LEVEL TO WINDOW ---
    // Make the camera show exactly the size of the level
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
    // Apply the custom view
    window.setView(m_view);

    Scene::display(window);
    for (const auto& gameObject : m_movableGameObjects)
        gameObject->draw(window);

    // Reset view so other things (like menus) draw normally
    window.setView(window.getDefaultView());
}

void LevelScene::clearLevel()
{
    for (auto* obj : m_movableGameObjects) delete obj;
    m_movableGameObjects.clear();
    for (auto* obj : m_gameObjects) delete obj;
    m_gameObjects.clear();
}

void LevelScene::onKeyPressed(const sf::Event::KeyPressed& event)
{
    for (auto* obj : m_movableGameObjects) obj->onKeyPressed(event);
}

void LevelScene::onKeyReleased(const sf::Event::KeyReleased& event)
{
    for (auto* obj : m_movableGameObjects) obj->onKeyReleased(event);
}