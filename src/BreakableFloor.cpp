#include "BreakableFloor.h"
#include "macros.h"

BreakableFloor::BreakableFloor(const sf::Vector2f& position)
	: RemovableGameObject(BREAKABLE_FLOOR, position)
{
}

void BreakableFloor::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}

void BreakableFloor::remove()
{
	m_isToBeRemoved = true;
}
