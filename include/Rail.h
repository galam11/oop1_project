#pragma once
#include "SpiritGameObject.h"
#include <SFML/Graphics.hpp>

class Rail : public SpiritGameObject
{
public:
	Rail(const sf::Vector2f& position);
	void handleColliton(GameObject& other) override;

	sf::FloatRect getGlobalBounds() const override;
};