#include "LevelScene.h"
#include "Coin.h"
#include "AssetsManager.h"
#include <iostream>

LevelScene::LevelScene()
{
    m_board.loadNextLevel();

    if (m_board.getTimeOut().asSeconds() != 0)
        m_timer.restart();
    else
        m_timer.reset();
}

void LevelScene::update(const sf::Time& dt)
{
	m_board.update(dt);
   
	m_board.handleCollisions();

    if (m_board.getPlayer().gotHit())
    {
        m_board.Reset();
    }
    else if (m_timer.getElapsedTime() > m_board.getTimeOut() || !m_board.isInBounds(m_board.getPlayer().getPositon()) || m_board.getPlayer().getLives() == 0)
    {
        m_board.loadFromRawBoard();

        if (m_board.getTimeOut().asSeconds() != 0)
            m_timer.restart();
        else
            m_timer.reset();
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

void LevelScene::nextLevel()
{
    m_board.loadNextLevel();

    if (m_board.getTimeOut().asSeconds() != 0)
        m_timer.restart();
    else
        m_timer.reset();
}

void LevelScene::resetLevel()
{
    m_board.Reset();
}