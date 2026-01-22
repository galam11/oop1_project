#include "Player.h"
#include "macros.h"
#include "Enemy.h"
#include "Board.h"

#include <iostream>
Player::Player(const sf::Vector2f& position)
	: MovableGameObject(PLAYER, position)
{
	m_speed = 400.f;
}

void Player::update(const sf::Time& dt)
{
	m_gotHit = false;
	sf::Vector2f moveDirection = { 0.f, 0.f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && isOnLadder())
		moveDirection += UP;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		moveDirection += DOWN;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		moveDirection += RIGHT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		moveDirection += LEFT;

	updatePositon(moveDirection, dt);
}

void Player::setPosition(const sf::Vector2f& position)
{
	setMyPosition(position);
	m_startPosition = position;
}

sf::Vector2f Player::getPositon() const
{
	return getGlobalBounds().getCenter();
}

void Player::handleColliton(const Enemy& other)
{
	m_lives--;
	m_gotHit = true;
}

void Player::handleColliton(const Coin& other)
{
	m_score += 2 * m_currentLevel;
}

void Player::resetPlayerHealth()
{
	m_lives = 3;
}

void Player::nextLevel()
{
	m_score += 50 * m_currentLevel;
	m_currentLevel++;
}

int Player::getScore() const
{
	return m_score;
}

int Player::getLives() const
{
	return m_lives;
}

int Player::getCurrentLevel() const
{
	return m_currentLevel;
}

bool Player::gotHit() const
{
	return m_gotHit;
}

void Player::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
