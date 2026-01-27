#include "Controller.h"
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "LevelScene.h"
#include "MainMenueScene.h"
#include "AssetsManager.h"
#include "macros.h"

Controller::Controller()
	: m_window(sf::VideoMode(WINDOW_SIZE), "Game Window")
{
	m_window.setIcon(AssetsManager::instance().getTexture(PLAYER_SINGLE).copyToImage());
	m_window.setTitle(TITLE_TEXT);

	m_currentScene = std::make_unique<MainMenuScene>();

	m_backround.setTexture(&AssetsManager::instance().getTexture(ID::BACKROUND));
	m_backround.setSize({ (float)WINDOW_SIZE.x, (float)WINDOW_SIZE.y });
	m_backround.setTextureRect({ {0 ,0} , { (int)WINDOW_SIZE.x * 2, (int)WINDOW_SIZE.y * 2 } });
}

void Controller::run()
{
	sf::Clock gameClock;
	while (m_window.isOpen())
	{
		if (m_currentScene->isSceneFinished())
			m_currentScene = std::move(m_currentScene->getNextSeane());

		while (auto event = m_window.pollEvent())
			event->visit([this](const auto& ev) { handleEvent(ev); });

		m_currentScene->update(gameClock.restart());


		m_window.draw(m_backround);
		m_currentScene->display(m_window);

		m_window.display();
	}
}


void Controller::handleEvent(const auto& event) { }

void Controller::handleEvent(const sf::Event::Closed& event)
{
	m_window.close();
}

void Controller::handleEvent(const sf::Event::KeyPressed& event)
{
	m_currentScene->onKeyPressed(event);
}

void Controller::handleEvent(const sf::Event::KeyReleased& event)
{
	m_currentScene->onKeyReleased(event);
}
