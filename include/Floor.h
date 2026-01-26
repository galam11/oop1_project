#pragma once
#include "SpiritGameObject.h"
#include <SFML/Graphics.hpp>

class Floor : public SpiritGameObject
{
public:
	Floor(const sf::Vector2f& position);

	void handleColliton(GameObject& other) override;
};