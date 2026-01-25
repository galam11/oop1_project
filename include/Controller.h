#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <memory>

class Controller
{
public:
	Controller();

	void run();
private:
	std::unique_ptr<Scene> m_nextScene = nullptr;
	std::unique_ptr<Scene> m_currentScene;
	sf::RenderWindow m_window;

	void handleEvent(const auto& event);
	void handleEvent(const sf::Event::Closed& event);
	void handleEvent(const sf::Event::KeyPressed& event);
	void handleEvent(const sf::Event::KeyReleased& event);
};