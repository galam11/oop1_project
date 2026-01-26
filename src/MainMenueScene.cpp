#include "MainMenueScene.h"
#include "LevelScene.h"
#include "AssetsManager.h"
#include "macros.h"

MainMenuScene::MainMenuScene()
    : m_title(AssetsManager::instance().getFont()),
    m_rulesText(AssetsManager::instance().getFont())  // Initialize with font
{
    // animated background
    m_board.loadNextLevel();

    // Setup Title
    m_title.setString("LODE RUNNER");
    m_title.setCharacterSize(100);
    m_title.setFillColor(sf::Color::Yellow);
    // Center the title horizontally
    auto titleBounds = m_title.getGlobalBounds();
    m_title.setPosition({ WINDOW_SIZE.x / 2.f - titleBounds.size.x / 2.f, 100.f });

    // Initialize Buttons
    initButton("START GAME", 400.f);
    initButton("INSTRUCTIONS", 500.f);
    initButton("EXIT", 600.f);

    // Setup Instructions text
    m_rulesText.setString("Rules:\n- Collect all coins \n- Avoid enemies \n- Go up and down on ladders\n- Go left or right on rails\n\nPress Enter to return");
    m_rulesText.setCharacterSize(35);
    m_rulesText.setFillColor(sf::Color::White);
    auto rulesBounds = m_rulesText.getGlobalBounds();
    m_rulesText.setPosition({ WINDOW_SIZE.x / 2.f - rulesBounds.size.x / 2.f, 350.f });

    // initial highlighted button
    updateSelection();
}

void MainMenuScene::initButton(const std::string& str, float yPos)
{
    sf::Text text(AssetsManager::instance().getFont(), str, 50);
    auto bounds = text.getGlobalBounds();
    text.setPosition({ WINDOW_SIZE.x / 2.f - bounds.size.x / 2.f, yPos });

    m_buttons.push_back(std::move(text));
}

void MainMenuScene::updateSelection() // highlights selected button
{
    for (int i = 0; i < m_buttons.size(); ++i)
    {
        m_buttons[i].setFillColor(i == m_selectedIndex ? sf::Color::Red : sf::Color::White);
    }
}

void MainMenuScene::update(const sf::Time& dt)
{
    m_board.update(dt);
}

void MainMenuScene::onKeyPressed(const sf::Event::KeyPressed& event)
{
    if (m_showInstructions)
    {
        if (event.code == sf::Keyboard::Key::Enter || event.code == sf::Keyboard::Key::Escape)
            m_showInstructions = false;
        return;
    }

    // Menu Navigation
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
        // Selection Logic
        switch (m_selectedIndex)
        {
        case Start:
            m_nextSeane = std::make_unique<LevelScene>();
            break;
        case Instructions:
            m_showInstructions = true;
            break;
        case Exit:
            exit(0);
            break;
        }
    }
}

void MainMenuScene::display(sf::RenderWindow& window) const
{
    m_board.display(window);

    if (m_showInstructions)
    {
        window.draw(m_rulesText);
    }
    else
    {
        window.draw(m_title);
        for (const auto& btn : m_buttons)
        {
            window.draw(btn);
        }
    }
}