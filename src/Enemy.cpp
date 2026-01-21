#include "Enemy.h"
#include <cmath>

Enemy::Enemy(const sf::Vector2f& position, const Player& player) : 
	MovableGameObject(ENEMY, position), m_target(position),
	m_player(player)
{
	m_speed = 50.f;
}

void Enemy::update(const sf::Time& dt)
{
	// Simple AI: Move towards the target
	m_target = m_player.getPositon();

	sf::Vector2f direction = m_target - getGlobalBounds().getCenter();
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	

	if (distance > 1.0f)
	{
		direction = direction / distance;
	}
	else
	{
		direction = { 0.f, 0.f };
	}

	updatePositon(direction, dt);
}

void Enemy::setTarget(const sf::Vector2f& newTarget)
{
	m_target = newTarget;
}

void Enemy::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
