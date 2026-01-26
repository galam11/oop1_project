#pragma once
#include "SpiritGameObject.h"

enum ID;
class RemovableGameObject : public SpiritGameObject
{
public:
	RemovableGameObject(ID type, const sf::Vector2f& position);
	bool isToBeRemoved() const;

protected:
	bool m_isToBeRemoved = false;
};
