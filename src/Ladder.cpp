#include "Ladder.h"
#include "macros.h"
#include <SFML/Graphics.hpp>

Ladder::Ladder(const sf::Vector2f& position)
	: GameObject(LADDER, position)
{
}

void Ladder::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
