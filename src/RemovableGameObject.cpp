#include "RemovableGameObject.h"
#include "macros.h"


RemovableGameObject::RemovableGameObject(ID type, const sf::Vector2f& position)
	: SpriteGameObject(type, position) { }


bool RemovableGameObject::isToBeRemoved() const
{
	return m_isToBeRemoved;
}
