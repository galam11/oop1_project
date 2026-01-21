#include "MovableGameObject.h"

#include "Floor.h"
#include "BreakableFloor.h"
#include "Ladder.h"
#include "Rail.h"

#include "macros.h"

MovableGameObject::MovableGameObject(Types type, const sf::Vector2f& position)
	: GameObject(type, position), m_startPosition(position) { }

void MovableGameObject::resetGameObject()
{
	setMyPosition(m_startPosition);
}

void MovableGameObject::handleColliton(const Floor& other)
{
	handleSolidCollision(other);
	m_onGround = true;
}

void MovableGameObject::handleColliton(const BreakableFloor& other)
{
	handleSolidCollision(other);
	m_onGround = true;
}

void MovableGameObject::handleColliton(const Ladder& other)
{
	m_onLadder = true;
}

void MovableGameObject::handleColliton(const Rail& other)
{
	m_onRail = true;
	if (!m_onLadder && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		auto diff = other.getGlobalBounds().getCenter() - getGlobalBounds().getCenter();
		diff.x = 0.f;

		if (diff.y != 0)
			moveMe(diff.normalized() * 2.f);
	}
}

void MovableGameObject::updatePositon(sf::Vector2f moveVec, const sf::Time& dt)
{
	if (!m_onLadder && !m_onRail)
		moveVec += DOWN  * (m_onGround ? 1.f : GRAVITY);

	moveMe(moveVec * m_speed * dt.asSeconds());
	m_onLadder = m_onRail = m_onGround = false;
}

bool MovableGameObject::isOnLadder() const
{
	return m_onLadder;
}

bool MovableGameObject::isOnRail() const
{
	return m_onRail;
}

void MovableGameObject::handleSolidCollision(const GameObject& other)
{
	auto bounds = getGlobalBounds().findIntersection(other.getGlobalBounds()).value();

	auto dir = other.getGlobalBounds().position - getGlobalBounds().position;

	dir.x = (dir.x == 0) ? 0 : ((dir.x > 0) ? -1 : 1);
	dir.y = (dir.y == 0) ? 0 : ((dir.y > 0) ? -1 : 1);

	if (bounds.size.x < bounds.size.y)
		moveMe({ bounds.size.x * dir.x, 0.f });
	else
		moveMe({ 0.f, bounds.size.y * dir.y });
}

