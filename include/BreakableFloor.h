#pragma once

#include <sfml/Graphics.hpp>
#include "RemovableGameObject.h"

class BreakableFloor : public RemovableGameObject
{
public:
	BreakableFloor(const sf::Vector2f& position);

	void handleColliton(GameObject& other) override;
};