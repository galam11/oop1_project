#include "Player.h"
#include "macros.h"
#include <Floor.h>
#include <iostream>
Player::Player(const sf::Vector2f& position)
	: MovableGameObject(PLAYER, position), m_score(0), m_coins(0)
{
	m_speed = 400.f;
}

void Player::update(const sf::Time& dt)
{
	m_moveDirection = { 0.f, 1.f };


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		m_moveDirection += UP;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		m_moveDirection += RIGHT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		m_moveDirection += LEFT;

	updatePositon(dt);
}

void Player::setPosition(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
	m_startPosition = position;
}

sf::Vector2f Player::getPositon() const
{
	return m_sprite.getPosition();
}

void Player::handleColliton(const Floor& other)
{
	auto diff = getGlobalBounds().findIntersection(other.getGlobalBounds()).value().size.y;

	auto dir = (getGlobalBounds().position - other.getGlobalBounds().position);

	dir.x = 0;
	if (dir.y == 0) return;

	dir = dir.normalized();
	m_sprite.move(dir * diff);
}

void Player::handleColliton(const Enemy& other)
{
	resetPosition();
}

int Player::getCoins() const
{
	return m_coins;
}

int Player::getScore() const
{
	return m_score;
}

void Player::increseCoins()
{
	++m_coins;
}

void Player::increseScore(int amount)
{
	m_score += amount;
}

void Player::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
