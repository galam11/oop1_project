#include "Conntroller.h"
#include "Conntroller.h"
#include "Conntroller.h"
#include "Conntroller.h"
#include "Conntroller.h"
#include <SFML/Graphics.hpp>
#include "Scene.h"


Controller::Controller()
	: m_window(sf::VideoMode({ 800, 600 }), "Game Window")
{
	
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		while (auto event = m_window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				m_window.close();
			}
		}
	}
}

void Controller::setScene(Scene* scene)
{
	m_nextScene = scene;
}

void Controller::handleEvent(const auto& event) { }

void Controller::handleCloseEvent(const sf::Event::Closed& event)
{
	m_window.close();
}

void Controller::handleKeyReleasedEvent(const sf::Event::KeyPressed& event)
{
}

void Controller::handleKeyPressedEvent(const sf::Event::KeyReleased& event)
{
}
