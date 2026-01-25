#pragma once
#include "GameObject.h"

enum ID;
class RemovableGameObject : public GameObject
{
public:
	RemovableGameObject(ID type, const sf::Vector2f& position);
	bool isToBeRemoved() const;

protected:
	bool m_isToBeRemoved = false;
};
