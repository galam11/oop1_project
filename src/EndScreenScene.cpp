#include "EndScreenScene.h"
#include "LevelScene.h"
#include "MainMenueScene.h"
#include "AssetsManager.h"
#include "macros.h"

EndScreenScene::EndScreenScene(bool victory, int score)
    : MenuScene(MENUE_BORAD_FILE_PATH, victory ? SoundID::VICTORY : SoundID::FAILURE),
    m_statusText(AssetsManager::instance().getFont(), victory ? WIN_TEXT : LOOS_TEXT, LARG_FONT_SIZE),
    m_scoreText(AssetsManager::instance().getFont(), SCORE_SHOWCASE_TEXT + std::to_string(score), FORNT_SIZE)
{
    m_board.loadNextLevel();
    m_sceneSound.play();

    AssetsManager::instance().setMusicVolume(20.f);

    m_statusText.setFillColor(victory ? sf::Color::Green : sf::Color::Red);
    auto statusBounds = m_statusText.getGlobalBounds();
    m_statusText.setPosition({ WINDOW_SIZE.x / 2.f - statusBounds.size.x / 2.f, 100.f });
    m_statusText.setOutlineColor(sf::Color::Black);
    m_statusText.setOutlineThickness(5.f);

    m_scoreText.setFillColor(sf::Color::White);
    auto scoreBounds = m_scoreText.getGlobalBounds();
    m_scoreText.setPosition({ WINDOW_SIZE.x / 2.f - scoreBounds.size.x / 2.f, 250.f });
    m_scoreText.setOutlineColor(sf::Color::Black);
    m_scoreText.setOutlineThickness(3.f);

    initButton("RESTART", 450.f, 50);
    initButton("MAIN MENU", 550.f, 50);
    initButton("EXIT", 650.f, 50);

    updateSelection();
}

void EndScreenScene::onKeyPressed(const sf::Event::KeyPressed& event)
{
    MenuScene::onKeyPressed(event);

    if (event.code == sf::Keyboard::Key::Enter)
    {
        switch (m_selectedIndex)
        {
        case Restart:
            m_nextSeane = std::make_unique<LevelScene>();
            break;
        case MainMenu:
            m_nextSeane = std::make_unique<MainMenuScene>();
            break;
        case Exit:
            exit(EXIT_SUCCESS);
            break;
        }
    }
}

void EndScreenScene::display(sf::RenderWindow& window) const
{
    m_board.display(window);
    window.draw(m_statusText);
    window.draw(m_scoreText);
    drawButtons(window);
}