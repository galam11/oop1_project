#include "Enemy.h"
#include <cmath>

Enemy::Enemy(const sf::Vector2f& position)
	: MovableGameObject(ENEMY, position), m_target(position)
{
	m_target = { 0.f, 0.f }; // temp for testing algorithm

	m_speed = 50.f;
}

void Enemy::update()
{
	// Simple AI: Move towards the target
	sf::Vector2f direction = m_target - getPositon();
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	// Only move if we are not already at the target
	if (distance > 1.0f)
	{
		// Normalize direction
		m_moveDirection = direction / distance;
	}
	else
	{
		m_moveDirection = { 0.f, 0.f };
	}
}

void Enemy::setTarget(const sf::Vector2f& newTarget)
{
	m_target = newTarget;
}