#pragma once
#include "GameObject.h"


class MovableGameObject : public GameObject
{
public:
	void setMoveDirection(const sf::Vector2f& dir);
	sf::Vector2f getMoveDirection() const;
private:
	sf::Vector2f m_moveDirection;
};
