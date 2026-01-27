#include "EndScreenScene.h"
#include "LevelScene.h"
#include "MainMenueScene.h"
#include "AssetsManager.h"
#include "macros.h"

EndScreenScene::EndScreenScene(bool victory, int score) : Scene(MENUE_BORAD_FILE_PATH, victory ? SoundID::VICTORY : SoundID::FAILURE),
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
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(3.f);

    m_buttons.push_back(std::move(text));
}

void EndScreenScene::updateSelection()
{
    for (int i = 0; i < (int)m_buttons.size(); ++i)
    {
        m_buttons[i].setFillColor(i == m_selectedIndex ? sf::Color::Red : sf::Color::White);
    }
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
    for (const auto& btn : m_buttons)
    {
        window.draw(btn);
    }
}

void EndScreenScene::update(const sf::Time& dt)
{
    Scene::update(dt);
    m_board.update(dt);
}
