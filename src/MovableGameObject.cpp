#include "MovableGameObject.h"
#include "Floor.h"
#include "BreakableFloor.h"
#include "Ladder.h"
#include "Rail.h"
#include "macros.h"
#include "Player.h"
#include <cmath>

enum
{
	ANIMATION_WALK_RIGHT = 0,
	ANIMATION_WALK_LEFT = 1,
	ANIMATION_LADDER = 2,
	ANIMATION_RAIL = 3
};

MovableGameObject::MovableGameObject(ID type, const sf::Vector2f& position)
	: SpiritGameObject(type, position), m_startPosition(position) { }

void MovableGameObject::update(const sf::Time& dt)
{
	if (!m_colidedWithRail && m_colidedWithRailLastFrame)
		m_ignoreRail = false;

	m_moveDirctaion = updateMovingGameobject(dt);
	updatePositon(dt);
	animate(dt);

	m_colidedWithRailLastFrame = m_colidedWithRail;
	m_colidedWithRail = false;
	m_onLadder = m_onRail = m_onGround = false;
}

void MovableGameObject::updatePositon(const sf::Time& dt)
{
	auto gravityVec = VEC2_ZERO;

	if (!m_onGround && !m_onLadder && !m_onRail)
		m_moveDirctaion.x = 0;

	if (m_moveDirctaion != VEC2_ZERO)
		m_moveDirctaion = m_moveDirctaion.normalized();

	if (!m_onLadder && !m_onRail)
		gravityVec = DOWN * (m_onGround ? 50.f : GRAVITY);

	moveMe((m_moveDirctaion * m_speed + gravityVec) * dt.asSeconds());
}

void MovableGameObject::animate(const sf::Time& dt)
{
	if (m_moveDirctaion == VEC2_ZERO)
		m_animator.resetAnimation();
	else
	{
		m_animator.setAnimation(m_moveDirctaion.x > 0 ? ANIMATION_WALK_RIGHT : ANIMATION_WALK_LEFT);

		if (m_onLadder && m_moveDirctaion.y != 0)
			m_animator.setAnimation(ANIMATION_LADDER);


		if (m_onRail && m_moveDirctaion.x != 0)
			m_animator.setAnimation(ANIMATION_RAIL);

		m_animator.animate(dt);
	}
	
}

void MovableGameObject::reset() 
{ 
	m_animator.setAnimation(ANIMATION_WALK_RIGHT);
	m_animator.resetAnimation();

	setMyPosition(m_startPosition); 
}

sf::FloatRect MovableGameObject::getGlobalBounds() const
{
	return scaleBoundingBoxFromCenter(0.6f, 1.f);
}

void MovableGameObject::handleColliton(Floor& other) { handleSolidCollision(other); }
void MovableGameObject::handleColliton(BreakableFloor& other) { handleSolidCollision(other); }

void MovableGameObject::handleColliton(Ladder& other)
{
	m_onLadder = true;

	if (std::abs(m_moveDirctaion.x) > 0.1f) return;


	auto ladderCenter = other.getGlobalBounds().getCenter();
	float diffX = ladderCenter.x - getGlobalBounds().getCenter().x;

	if (std::abs(diffX) < GO_TEXTURE_DIMANTION * 0.5f) 
	{
		moveMe({ diffX * 0.2f, 0.f });
	}
}

void MovableGameObject::handleColliton(Rail& other)
{
	m_colidedWithRail = true;
	if (m_moveDirctaion.y > 0.2) m_ignoreRail = true;
	if (!m_onLadder && !m_ignoreRail) {
		m_onRail = true;
		auto diff = other.getGlobalBounds().getCenter() - getGlobalBounds().getCenter();
		diff.x = 0.f;
		if (diff.y != 0) moveMe(diff.normalized());
	}
}

void MovableGameObject::handleSolidCollision(const SpiritGameObject& other)
{
	auto intersection = getGlobalBounds().findIntersection(other.getGlobalBounds());

	auto bounds = intersection.value();
	auto dir = other.getGlobalBounds().position - getGlobalBounds().position;
	dir.x = (dir.x == 0) ? 0 : ((dir.x > 0) ? -1 : 1);
	dir.y = (dir.y == 0) ? 0 : ((dir.y > 0) ? -1 : 1);

	if (m_onLadder && m_moveDirctaion.y < 0 && bounds.size.y < 15.0f)
		return;

	if (bounds.size.x < bounds.size.y) {
		moveMe({ bounds.size.x * dir.x, 0.f });
	}
	else {
		moveMe({ 0.f, bounds.size.y * dir.y });
		if (dir.y < 0) m_onGround = true;
	}
}

bool MovableGameObject::isOnLadder() const { return m_onLadder; }
bool MovableGameObject::isOnRail() const { return m_onRail; }