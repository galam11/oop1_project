#pragma once
#include "SpiritGameObject.h"
#include <SFML/Graphics.hpp>

class Ladder : public SpiritGameObject
{
public:
	Ladder(const sf::Vector2f& position);

	void handleColliton(GameObject& other) override;

	sf::FloatRect getGlobalBounds() const override;
};