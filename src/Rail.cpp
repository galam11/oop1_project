#include "Rail.h"
#include "macros.h"
#include <SFML/Graphics.hpp>

Rail::Rail(const sf::Vector2f& position)
	: SpiritGameObject(RAIL, position)
{
}

void Rail::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
