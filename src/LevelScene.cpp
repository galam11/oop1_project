#include "LevelScene.h"
#include "Coin.h"
#include <iostream>

LevelScene::LevelScene()
{
    m_board.loadNextLevel();
}

void LevelScene::update(const sf::Time& dt)
{
	m_board.update(dt);
   
	m_board.handleCollisions();

    if (m_board.getPlayer().gotHit())
    {
        m_board.Reset();
		std::cout << "Player got hit! Lives left: " << m_board.getPlayer().getLives() << std::endl;
    }
    else if (!m_board.isInBounds(m_board.getPlayer().getPositon()) || m_board.getPlayer().getLives() == 0)
    {
        m_board.loadFromRawBoard();
		std::cout << "Player lost! Try again ! Lives left: " << m_board.getPlayer().getLives() << std::endl;
    }

    if (Coin::getCoinCount() == 0)
        m_board.loadNextLevel();
}

void LevelScene::display(sf::RenderWindow& window) const
{
	m_board.display(window);
}


// for debuge
void LevelScene::onKeyReleased(const sf::Event::KeyReleased& event)
{
    if (event.code == sf::Keyboard::Key::Space)
        m_board.loadNextLevel();

    else if (event.code == sf::Keyboard::Key::R)
        m_board.loadFromRawBoard();
}