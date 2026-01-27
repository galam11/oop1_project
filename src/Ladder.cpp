#include "Ladder.h"
#include "macros.h"
#include <SFML/Graphics.hpp>

Ladder::Ladder(const sf::Vector2f& position)
	: SpiritGameObject(LADDER, position)
{
}

void Ladder::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}

sf::FloatRect Ladder::getGlobalBounds() const
{
	return scaleBoundingBoxFromCenter(0.7f , 1.f);
}
