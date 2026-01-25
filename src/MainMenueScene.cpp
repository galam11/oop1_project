#include "MainMenueScene.h"
#include "macros.h"
#include "memory.h"
#include "LevelScene.h"
void MainMenuScene::update(const sf::Time& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		m_nextSeane = std::make_unique<LevelScene>();
	}
}

void MainMenuScene::display(sf::RenderWindow& window) const
{
}