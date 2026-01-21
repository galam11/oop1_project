#include "HideableGameObject.h"
#include "macros.h"


RemovableGameObject::RemovableGameObject(Types type, const sf::Vector2f& position)
	: GameObject(type, position) { }


bool RemovableGameObject::isToBeRemoved() const
{
	return m_isToBeRemoved;
}
