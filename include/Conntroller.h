#pragma once

#include <SFML/Graphics.hpp>
#include "Sean.h"
class Controller
{
	void run();
	void setSean(Scene* sean);
private:
	sf::RenderWindow m_window;
	Scene* m_nextSean = nullptr;
	Scene* m_currentSean = nullptr;
};