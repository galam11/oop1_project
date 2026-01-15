#pragma once
#include "GameObject.h"
#include <sfml/Graphics.hpp>

class BreakableFloor : public GameObject
{
public:
	BreakableFloor(const sf::Vector2f& position);

	void handleColliton(GameObject& other) override;
};