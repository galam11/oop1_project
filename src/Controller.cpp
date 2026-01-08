#include "Controller.h"
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "LevelScene.h"

#include <iostream>

Controller::Controller()
	: m_window(sf::VideoMode({ 800, 600 }), "Game Window")
{
	m_currentScene = std::make_unique<LevelScene>();
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		while (auto event = m_window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				m_window.close();
			else 
				event->visit([this](const auto& ev) { handleEvent(ev); });
		}

		m_currentScene->update();

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

void Controller::handleKeyReleasedEvent(const sf::Event::KeyPressed& event)
{
	std::cout << "Key Pressed: " << sf::Keyboard::getDescription(event.scancode).toAnsiString() << std::endl;
	m_currentScene->onKeyPressed(event);
}

void Controller::handleKeyPressedEvent(const sf::Event::KeyReleased& event)
{
	std::cout << "Key Released: " << sf::Keyboard::getDescription(event.scancode).toAnsiString() << std::endl;
	m_currentScene->onKeyReleased(event);
}
