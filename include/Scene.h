#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>
class Scene
{
public:
	virtual void update();
	virtual void onEvent(const sf::Event& event);
	virtual void display(sf::RenderWindow& window) const;
private:
	std::vector<GameObject*> m_gameObjects;
};