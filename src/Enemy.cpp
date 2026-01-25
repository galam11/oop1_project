#include "Enemy.h"
#include "macros.h"

Enemy::Enemy(const sf::Vector2f& position, const Player& player) : 
	MovableGameObject(ENEMY, position),
	m_player(player)
{
	m_speed = 100.f;
}

sf::Vector2f Enemy::updateMovingGameobject(const sf::Time& dt)
{
	auto dir = m_player.getPositon() - getGlobalBounds().getCenter();

	return dir;
}

void Enemy::setTarget(const sf::Vector2f& newTarget)
{
	m_target = newTarget;
}

void Enemy::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
