#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class MovableGameObject : public GameObject
{
public:
	MovableGameObject(char type, const sf::Vector2f& position);

	virtual void update(const sf::Time& dt) = 0;

	void resetPosition();

	sf::Vector2f getMoveDirection() const;
protected:

	sf::Vector2f m_moveDirection = { 0, 0 };
	float m_speed = 1.0f;

	sf::Vector2f m_startPosition;

	void updatePositon(const sf::Time& dt);
};