#include "MainMenueScene.h"
#include "LevelScene.h"
#include "AssetsManager.h"
#include "macros.h"


MainMenuScene::MainMenuScene() : Scene(MENUE_BORAD_FILE_PATH),
    m_title(AssetsManager::instance().getFont(), TITLE_TEXT, TITLE_FONT_SIZE),
    m_rulesText(AssetsManager::instance().getFont(), RULES_TEXT, FORNT_SIZE)
{
    AssetsManager::instance().setMusicVolume(100.f);
    AssetsManager::instance().playMusic();

    m_board.loadNextLevel();

    m_rulesText.setOutlineColor(sf::Color::Black);
    m_rulesText.setOutlineThickness(3.f);

    m_title.setOutlineColor(sf::Color::Black);
    m_title.setOutlineThickness(5.f);
    m_title.setFillColor(sf::Color::Yellow);
    auto titleBounds = m_title.getGlobalBounds();
    m_title.setPosition({ WINDOW_SIZE.x / 2.f - titleBounds.size.x / 2.f, 100.f });

    initButton("START GAME", 400.f);
    initButton("INSTRUCTIONS", 500.f);
    initButton("EXIT", 600.f);

    
    m_rulesText.setCharacterSize(FORNT_SIZE);
    m_rulesText.setFillColor(sf::Color::White);
    auto rulesBounds = m_rulesText.getGlobalBounds();
    m_rulesText.setPosition({ WINDOW_SIZE.x / 2.f - rulesBounds.size.x / 2.f, 350.f });

    updateSelection();
}

void MainMenuScene::initButton(const std::string& str, float yPos)
{
    sf::Text text(AssetsManager::instance().getFont(), str, FORNT_SIZE);

    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(3.f);

    auto bounds = text.getGlobalBounds();
    text.setPosition({ WINDOW_SIZE.x / 2.f - bounds.size.x / 2.f, yPos });
    m_buttons.push_back(std::move(text));
}

void MainMenuScene::updateSelection()
{
    for (int i = 0; i < (int)m_buttons.size(); ++i)
    {
        m_buttons[i].setFillColor(i == m_selectedIndex ? sf::Color::Red : sf::Color::White);
    }
}

void MainMenuScene::onKeyPressed(const sf::Event::KeyPressed& event)
{
    if (m_showInstructions)
    {
        if (event.code == sf::Keyboard::Key::Enter || event.code == sf::Keyboard::Key::Escape)
            m_showInstructions = false;
        return;
    }

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