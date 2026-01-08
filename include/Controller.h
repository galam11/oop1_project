#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <memory>

class Controller
{
public:
	Controller();

	void run();
	void setScene(std::unique_ptr<Scene>& scene);
private:
	std::unique_ptr<Scene> m_nextScene;
	std::unique_ptr<Scene> m_currentScene = nullptr;
	sf::RenderWindow m_window;

	void handleEvent(const auto& event);
	void handleKeyReleasedEvent(const sf::Event::KeyPressed& event);
	void handleKeyPressedEvent(const sf::Event::KeyReleased& event);

	void processEvents()
	{
		
	}
};