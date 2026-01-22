#include "Enemy.h"
#include "macros.h"

Enemy::Enemy(const sf::Vector2f& position, const Player& player) : 
	MovableGameObject(ENEMY, position),
	m_player(player)
{
	m_speed = 100.f;
}

void Enemy::update(const sf::Time& dt)
{
	updatePositon(m_player.getPositon() - getGlobalBounds().getCenter(), dt);
}

void Enemy::setTarget(const sf::Vector2f& newTarget)
{
	m_target = newTarget;
}

void Enemy::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
