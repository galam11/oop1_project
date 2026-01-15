#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Ladder : public GameObject
{
public:
	Ladder(const sf::Vector2f& position);

	void handleColliton(GameObject& other) override;
};