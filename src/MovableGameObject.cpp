#include "MovableGameObject.h"
#include "Floor.h"
#include "BreakableFloor.h"
#include "Ladder.h"
#include "Rail.h"
#include "macros.h"
#include "Player.h"
#include <cmath>

MovableGameObject::MovableGameObject(ID type, const sf::Vector2f& position)
	: SpiritGameObject(type, position), m_startPosition(position) {
}

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
	if (m_moveDirctaion != VEC2_ZERO)
		m_moveDirctaion = m_moveDirctaion.normalized();

	// Fix: Restrict mid-air movement (Lode Runner mechanics)
	if (!m_onGround && !m_onLadder && !m_onRail)
		m_moveDirctaion.x = 0;

	// Apply gravity only if not supported by a ladder or rail
	if (!m_onLadder && !m_onRail)
		gravityVec = DOWN * (m_onGround ? 50.f : GRAVITY);

	moveMe((m_moveDirctaion * m_speed + gravityVec) * dt.asSeconds());
}

void MovableGameObject::animate(const sf::Time& dt)
{
	if (m_moveDirctaion == VEC2_ZERO)
		m_animator.resetAnimation();
	else {
		m_animator.setAnimation(m_moveDirctaion.x > 0 ? 0 : 1);
		m_animator.animate(dt);
	}
}

void MovableGameObject::reset() { setMyPosition(m_startPosition); }

sf::FloatRect MovableGameObject::getGlobalBounds() const
{
	// Narrowed collision box allows character to fit through 1-tile gaps even if slightly off-center
	return scaleRectFromCenter(SpiritGameObject::getGlobalBounds(), 0.6f, 1.f);
}

void MovableGameObject::handleColliton(Floor& other) { handleSolidCollision(other); }
void MovableGameObject::handleColliton(BreakableFloor& other) { handleSolidCollision(other); }

void MovableGameObject::handleColliton(Ladder& other)
{
	// FIX: Interaction depends on simply overlapping the ladder
	m_onLadder = true;

	// Only align to the vertical center axis if there is vertical intent (climbing)
	if (std::abs(m_moveDirctaion.y) > 0.1f)
	{
		auto ladderCenter = other.getGlobalBounds().getCenter();
		float diffX = ladderCenter.x - getGlobalBounds().getCenter().x;

		// Snap to ladder vertical line if within reasonable distance
		if (std::abs(diffX) < GO_TEXTURE_DIMANTION * 0.5f) {
			moveMe({ diffX * 0.2f, 0.f }); // Proportional centering alignment
		}
	}
}

void MovableGameObject::handleColliton(Rail& other)
{
	m_colidedWithRail = true;
	if (m_moveDirctaion.y > 0) m_ignoreRail = true;
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
	if (!intersection) return;

	auto bounds = intersection.value();
	auto dir = other.getGlobalBounds().position - getGlobalBounds().position;
	dir.x = (dir.x == 0) ? 0 : ((dir.x > 0) ? -1 : 1);
	dir.y = (dir.y == 0) ? 0 : ((dir.y > 0) ? -1 : 1);

	// FIX: Ladder-Floor blockage at the top
	// Allow characters to move through floor overlap if they are climbing UP a ladder
	if (m_onLadder && m_moveDirctaion.y < 0 && bounds.size.y < 15.0f)
		return;

	if (bounds.size.x < bounds.size.y) {
		// Horizontal pushback: ensures character fits in narrow passages correctly
		moveMe({ bounds.size.x * dir.x, 0.f });
	}
	else {
		// Vertical pushback
		moveMe({ 0.f, bounds.size.y * dir.y });
		if (dir.y < 0) m_onGround = true;
	}
}

bool MovableGameObject::isOnLadder() const { return m_onLadder; }
bool MovableGameObject::isOnRail() const { return m_onRail; }