#include "LevelScene.h"
#include "Coin.h"
#include "AssetsManager.h"
#include "EndScreenScene.h"

LevelScene::LevelScene()
    : m_hud(m_board.getPlayer(), m_timer, m_board)
{
    nextLevel();
}

void LevelScene::update(const sf::Time& dt)
{
    m_hud.update();
    m_board.update(dt);

    if (Coin::getCoinCount() == 0)
    {
        nextLevel();
    }
    else if (m_board.getPlayer().gotHit() || !m_board.isInBounds(m_board.getPlayer().getPositon()))
    {
        softResetLevel();
    }
    else if (m_timer.getElapsedTime() > m_board.getTimeOut())
    {
        hardResetLevel();
    }
    else if (m_board.getPlayer().getLives() == 0)
    {
        // FIX: Pass false (loss) and final score
        m_nextSeane = std::make_unique<EndScreenScene>(false, m_board.getPlayer().getScore());
    }
}

void LevelScene::display(sf::RenderWindow& window) const
{
    m_board.display(window);
    m_hud.dispaly(window);
}

void LevelScene::onKeyReleased(const sf::Event::KeyReleased& event)
{
    if (event.code == sf::Keyboard::Key::Space)
        nextLevel();
    else if (event.code == sf::Keyboard::Key::R)
        hardResetLevel();
}

void LevelScene::nextLevel()
{
    if (!m_board.loadNextLevel())
    {
        // FIX: Pass true (victory) and final score
        m_nextSeane = std::make_unique<EndScreenScene>(true, m_board.getPlayer().getScore());
        return;
    }

    m_timer.reset();

    if (m_board.getTimeOut().asSeconds() != 0)
        m_timer.start();
}

void LevelScene::hardResetLevel()
{
    m_board.loadFromRawBoard();
    if (m_board.getTimeOut().asSeconds() != 0)
        m_timer.restart();
}

void LevelScene::softResetLevel()
{
    m_board.Reset();
}