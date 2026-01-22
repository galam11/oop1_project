#pragma once
#include "GameObject.h"

enum Types;
class RemovableGameObject : public GameObject
{
public:
	RemovableGameObject(Types type, const sf::Vector2f& position);
	bool isToBeRemoved() const;

protected:
	bool m_isToBeRemoved = false;
};
