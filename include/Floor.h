#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Floor : public GameObject
{
public:
	Floor(const sf::Vector2f& position);
};