#pragma once

#include <sfml/Graphics.hpp>
#include "HideableGameObject.h"

class BreakableFloor : public RemovableGameObject
{
public:
	BreakableFloor(const sf::Vector2f& position);

	void handleColliton(GameObject& other) override;
};