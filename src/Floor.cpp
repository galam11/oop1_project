#include "Floor.h"
#include "macros.h"

Floor::Floor(const sf::Vector2f& position)
	: SpriteGameObject(FLOOR, position)
{
}

void Floor::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
