#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class Coin : public GameObject
{
public:
	Coin(const sf::Vector2f& position);
};