#include "Floor.h"
#include "macros.h"

Floor::Floor(const sf::Vector2f& position)
	: SpiritGameObject(FLOOR, position)
{
}

void Floor::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
