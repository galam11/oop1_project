#pragma once
#include "SpriteGameObject.h"
#include <SFML/Graphics.hpp>

class Floor : public SpriteGameObject
{
public:
	Floor(const sf::Vector2f& position);

	void handleColliton(GameObject& other) override;
};