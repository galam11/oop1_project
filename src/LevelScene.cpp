#include "LevelScene.h"
#include <iostream>

LevelScene::LevelScene()
{
    loadLevel();
}

void LevelScene::loadLevel()
{
    if (!m_board.loadNextLevel())
    {
        std::cout << "Game Over or No More Levels!" << std::endl;
        return;
    }
}

void LevelScene::update(const sf::Time& dt)
{
	m_board.update(dt);
}

void LevelScene::display(sf::RenderWindow& window) const
{
	m_board.display(window);
}


// for debuge
void LevelScene::onKeyReleased(const sf::Event::KeyReleased& event)
{
    if (event.code == sf::Keyboard::Key::Space)
        loadLevel();
}