#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"

class Controller
{
public:
	Controller();

	void run();
	void setScene(Scene* scene);
private:
	Scene* m_nextScene = nullptr;
	Scene* m_currentScene = nullptr;
	sf::RenderWindow m_window;

	void handleEvent(const auto& event);
	void handleCloseEvent(const sf::Event::Closed& event);
	void handleKeyReleasedEvent(const sf::Event::KeyPressed& event);
	void handleKeyPressedEvent(const sf::Event::KeyReleased& event);

	void processEvents()
	{
		
		while (m_window.isOpen())
		{
			while (auto event = m_window.pollEvent())
			{
				
			}
		}
	}
};