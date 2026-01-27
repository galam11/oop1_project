#include "MainMenueScene.h"
#include "LevelScene.h"
#include "AssetsManager.h"
#include "macros.h"

MainMenuScene::MainMenuScene()
    : MenuScene(MENUE_BORAD_FILE_PATH, SoundID::VICTORY),
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

    initButton("START GAME", 400.f, FORNT_SIZE);
    initButton("INSTRUCTIONS", 500.f, FORNT_SIZE);
    initButton("EXIT", 600.f, FORNT_SIZE);

    m_rulesText.setCharacterSize(FORNT_SIZE);
    m_rulesText.setFillColor(sf::Color::White);
    auto rulesBounds = m_rulesText.getGlobalBounds();
    m_rulesText.setPosition({ WINDOW_SIZE.x / 2.f - rulesBounds.size.x / 2.f, 100.f });

    updateSelection();
}

void MainMenuScene::onKeyPressed(const sf::Event::KeyPressed& event)
{
    if (m_showInstructions)
    {
        if (event.code == sf::Keyboard::Key::Enter || event.code == sf::Keyboard::Key::Escape)
            m_showInstructions = false;
        return;
    }

    MenuScene::onKeyPressed(event);

    if (event.code == sf::Keyboard::Key::Enter)
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
        drawButtons(window);
    }
}