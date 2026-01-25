#include "MovableGameObject.h"

#include "Floor.h"
#include "BreakableFloor.h"
#include "Ladder.h"
#include "Rail.h"

#include "macros.h"

#include "Player.h"

MovableGameObject::MovableGameObject(Types type, const sf::Vector2f& position)
	: GameObject(type, position), m_startPosition(position) { }

void MovableGameObject::updatePositon(sf::Vector2f moveDirctaion, const sf::Time& dt)
{
	m_moveDirctaion = moveDirctaion;
	auto gravityVec = VEC2_ZERO;

	if (m_moveDirctaion != VEC2_ZERO)
		m_moveDirctaion = m_moveDirctaion.normalized();

	if (!m_onLadder && !m_onRail)
		gravityVec = DOWN * (m_onGround ? 50.f : GRAVITY);

	moveMe((m_moveDirctaion * m_speed + gravityVec) * dt.asSeconds());

	m_onLadder = m_onRail = m_onGround = false;
}

void MovableGameObject::resetGameObject()
{
	setMyPosition(m_startPosition);
}

void MovableGameObject::handleColliton(const Floor& other)
{
	handleSolidCollision(other);
}

void MovableGameObject::handleColliton(const BreakableFloor& other)
{
	handleSolidCollision(other);
}

void MovableGameObject::handleColliton(const Ladder& other)
{
	m_onLadder = true;
	if (!m_moveDirctaion.x != 0 && !m_onGround)
	{
		auto diff = other.getGlobalBounds().getCenter() - getGlobalBounds().getCenter();
		diff.y = 0.f;

		if (diff.x != 0)
			moveMe(diff.normalized());
	}
}


void MovableGameObject::handleColliton(const Rail& other)
{
	if (!m_onLadder && !m_moveDirctaion.y > 0)
	{
		m_onRail = true;
		auto diff = other.getGlobalBounds().getCenter() - getGlobalBounds().getCenter();
		diff.x = 0.f;

		if (diff.y != 0)
			moveMe(diff.normalized());
	}
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
	{
		moveMe({ 0.f, bounds.size.y * dir.y });

		if (dir.y < 0) 
			m_onGround = true;
	}
}

