#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <MovableGameObject.h>
#include <vector>

class Scene
{
public:

	Scene() = default;
	virtual ~Scene();

	virtual void update(const sf::Time& dt) = 0;
	virtual void onKeyPressed(const sf::Event::KeyPressed& event) = 0;
	virtual void onKeyReleased(const sf::Event::KeyReleased& event) = 0;
	virtual void display(sf::RenderWindow& window) const;
protected:

	std::vector<GameObject*> m_gameObjects;
};