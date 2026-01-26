#include "EndScreenScene.h"
#include "LevelScene.h"
#include "MainMenueScene.h"
#include "AssetsManager.h"
#include "macros.h"

EndScreenScene::EndScreenScene(bool victory, int score)
    : m_statusText(AssetsManager::instance().getFont()),
    m_scoreText(AssetsManager::instance().getFont())
{
    // Load a background level (re-using board logic for live background)
    m_board.loadNextLevel();

    // Setup "Victory" or "Game Over"
    m_statusText.setString(victory ? "VICTORY!" : "GAME OVER");
    m_statusText.setCharacterSize(100);
    m_statusText.setFillColor(victory ? sf::Color::Green : sf::Color::Red);
    auto statusBounds = m_statusText.getGlobalBounds();
    m_statusText.setPosition({ WINDOW_SIZE.x / 2.f - statusBounds.size.x / 2.f, 100.f });

    // Setup Score display
    m_scoreText.setString("Final Score: " + std::to_string(score));
    m_scoreText.setCharacterSize(50);
    m_scoreText.setFillColor(sf::Color::White);
    auto scoreBounds = m_scoreText.getGlobalBounds();
    m_scoreText.setPosition({ WINDOW_SIZE.x / 2.f - scoreBounds.size.x / 2.f, 250.f });

    // Initialize Buttons
    initButton("RESTART", 450.f);
    initButton("MAIN MENU", 550.f);
    initButton("EXIT", 650.f);

    updateSelection();
}

void EndScreenScene::initButton(const std::string& str, float yPos)
{
    sf::Text text(AssetsManager::instance().getFont(), str, 50);
    auto bounds = text.getGlobalBounds();
    text.setPosition({ WINDOW_SIZE.x / 2.f - bounds.size.x / 2.f, yPos });
    m_buttons.push_back(std::move(text));
}

void EndScreenScene::updateSelection()
{
    for (int i = 0; i < (int)m_buttons.size(); ++i)
    {
        m_buttons[i].setFillColor(i == m_selectedIndex ? sf::Color::Red : sf::Color::White);
    }
}

void EndScreenScene::update(const sf::Time& dt)
{
    m_board.update(dt); // Animate background elements
}

void EndScreenScene::onKeyPressed(const sf::Event::KeyPressed& event)
{
    if (event.code == sf::Keyboard::Key::Up)
    {
        m_selectedIndex = (m_selectedIndex - 1 + Count) % Count;
        updateSelection();
    }
    else if (event.code == sf::Keyboard::Key::Down)
    {
        m_selectedIndex = (m_selectedIndex + 1) % Count;
        updateSelection();
    }
    else if (event.code == sf::Keyboard::Key::Enter)
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
            exit(0);
            break;
        }
    }
}

void EndScreenScene::display(sf::RenderWindow& window) const
{
    m_board.display(window); // Draw background level

    window.draw(m_statusText);
    window.draw(m_scoreText);
    for (const auto& btn : m_buttons)
    {
        window.draw(btn);
    }
}