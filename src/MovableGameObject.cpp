#include "MovableGameObject.h"


MovableGameObject::MovableGameObject(char type, const sf::Vector2f& position)
	: GameObject(type, position), m_startPosition(position)
{
}

sf::Vector2f MovableGameObject::getMoveDirection() const
{
	return m_moveDirection;
}

void MovableGameObject::updatePositon(const sf::Time& dt)
{
	m_sprite.move(m_moveDirection * m_speed * dt.asSeconds());
}

void MovableGameObject::resetPosition()
{
	m_sprite.setPosition(m_startPosition);
}