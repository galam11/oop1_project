#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Rail : public GameObject
{
public:
	Rail(const sf::Vector2f& position);
};