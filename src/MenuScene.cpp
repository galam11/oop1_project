#include "MenuScene.h"
#include "AssetsManager.h"
#include "macros.h"

MenuScene::MenuScene(const std::string& boardFilePath, SoundID soundId)
    : Scene(boardFilePath, soundId)
{
}

void MenuScene::update(const sf::Time& dt)
{
    Scene::update(dt);
    m_board.update(dt);
}

void MenuScene::onKeyPressed(const sf::Event::KeyPressed& event)
{
    if (m_buttons.empty()) return;

    if (event.code == sf::Keyboard::Key::Up)
    {
        m_selectedIndex = (m_selectedIndex - 1 + m_buttons.size()) % m_buttons.size();
        updateSelection();
    }
    else if (event.code == sf::Keyboard::Key::Down)
    {
        m_selectedIndex = (m_selectedIndex + 1) % m_buttons.size();
        updateSelection();
    }
}

void MenuScene::initButton(const std::string& str, float yPos, int fontSize)
{
    sf::Text text(AssetsManager::instance().getFont(), str, fontSize);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(3.f);

    auto bounds = text.getGlobalBounds();
    text.setPosition({ WINDOW_SIZE.x / 2.f - bounds.size.x / 2.f, yPos });

    m_buttons.push_back(std::move(text));
}

void MenuScene::updateSelection()
{
    for (int i = 0; i < (int)m_buttons.size(); ++i)
    {
        m_buttons[i].setFillColor(i == m_selectedIndex ? sf::Color::Red : sf::Color::White);
    }
}

void MenuScene::drawButtons(sf::RenderWindow& window) const
{
    for (const auto& btn : m_buttons)
    {
        window.draw(btn);
    }
}