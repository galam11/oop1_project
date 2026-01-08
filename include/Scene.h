#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>

class Scene
{
public:
	virtual void update() = 0;
	virtual void onKeyPressed(const sf::Event::KeyPressed& event) = 0;
	virtual void onKeyReleased(const sf::Event::KeyReleased& event) = 0;
	virtual void display(sf::RenderWindow& window) const = 0;
private:
	std::vector<GameObject*> m_gameObjects;
};