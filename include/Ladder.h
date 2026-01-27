#pragma once
#include "SpriteGameObject.h"
#include <SFML/Graphics.hpp>

class Ladder : public SpriteGameObject
{
public:
	Ladder(const sf::Vector2f& position);

	void handleColliton(GameObject& other) override;

	sf::FloatRect getGlobalBounds() const override;
};