#pragma once
#include "SpriteGameObject.h"

enum ID;
class RemovableGameObject : public SpriteGameObject
{
public:
	RemovableGameObject(ID type, const sf::Vector2f& position);
	bool isToBeRemoved() const;

protected:
	bool m_isToBeRemoved = false;
};
