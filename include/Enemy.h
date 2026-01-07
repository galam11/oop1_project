#pragma once
#include <SFML/Graphics.hpp>
#include "MovableGameObject.h"


class Enemy : public MovableGameObject
{
public:
	void setTargate(const sf::Vector2f& newTargate);
private:
	sf::Vector2f m_targate;
};