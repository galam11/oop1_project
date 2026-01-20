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
   
	m_board.handleCollisions();

    if (m_board.getPlayer().gotHit())
    {
        m_board.softReset();
		std::cout << "Player got hit! Lives left: " << m_board.getPlayer().getLives() << std::endl;
    }
    else if (!m_board.isInBounds(m_board.getPlayer().getPositon()) || m_board.getPlayer().getLives() == 0)
    {
        m_board.reset();
		std::cout << "Player lost! Try again ! Lives left: " << m_board.getPlayer().getLives() << std::endl;
    }
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