#pragma once
#include "SpriteGameObject.h"
#include <SFML/Graphics.hpp>

class Rail : public SpriteGameObject
{
public:
	Rail(const sf::Vector2f& position);
	void handleColliton(GameObject& other) override;

	sf::FloatRect getGlobalBounds() const override;
};