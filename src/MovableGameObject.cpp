#include "MovableGameObject.h"


MovableGameObject::MovableGameObject(char type, const sf::Vector2f& position)
	: GameObject(type, position) { }


sf::Vector2f MovableGameObject::getMoveDirection() const
{
	return m_moveDirection;
}

void MovableGameObject::updatePositon(const sf::Time& dt)
{
	setPosition(getPositon() + m_moveDirection * m_speed * dt.asSeconds());
}

void MovableGameObject::onKeyPressed(const sf::Event::KeyPressed& event) { }
void MovableGameObject::onKeyReleased(const sf::Event::KeyReleased& event) { }

