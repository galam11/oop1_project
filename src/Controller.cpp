#include "Controller.h"
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "LevelScene.h"


Controller::Controller()
	: m_window(sf::VideoMode(WINDOW_SIZE), "Game Window")
{
	m_currentScene = std::make_unique<LevelScene>();
}

void Controller::run()
{
	sf::Clock gameClock;
	while (m_window.isOpen())
	{
		while (auto event = m_window.pollEvent())
			event->visit([this](const auto& ev) { handleEvent(ev); });

		m_currentScene->update(gameClock.restart());

		m_window.clear();

		m_currentScene->display(m_window);

		m_window.display();
	}
}

void Controller::setScene(std::unique_ptr<Scene>& scene)
{
	m_nextScene = std::move(scene);
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
