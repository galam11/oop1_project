#include "Rail.h"
#include "macros.h"
#include <SFML/Graphics.hpp>

Rail::Rail(const sf::Vector2f& position)
	: SpriteGameObject(RAIL, position)
{
}

void Rail::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}

sf::FloatRect Rail::getGlobalBounds() const
{
	return scaleBoundingBoxFromCenter(1.f ,.2f);
}
