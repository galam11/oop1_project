#include "BreakableFloor.h"
#include "macros.h"

BreakableFloor::BreakableFloor(const sf::Vector2f& position)
	: GameObject(BREAKABLE_FLOOR, position)
{
}

void BreakableFloor::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
