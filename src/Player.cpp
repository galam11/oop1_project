#include "Player.h"
#include "macros.h"
#include <iostream>
#include "Enemy.h"
Player::Player(const sf::Vector2f& position)
	: MovableGameObject(PLAYER, position), m_score(0), m_coins(0)
{
	m_speed = 400.f;
}

void Player::update(const sf::Time& dt)
{
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

void Player::resetGameObject()
{
	setMyPosition(m_startPosition);
	m_gotHit = false;
}

void Player::resetPlayer()
{
	m_lives = 3;
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
	std::cout << "Player hit by Enemy!" << std::endl;

	std::cout << other.getGlobalBounds().getCenter().x << ", " << other.getGlobalBounds().getCenter().y << std::endl;
	m_lives--;
	m_gotHit = true;
}

int Player::getCoins() const
{
	return m_coins;
}

int Player::getScore() const
{
	return m_score;
}

int Player::getLives() const
{
	return m_lives;
}

bool Player::gotHit() const
{
	return m_gotHit;
}

void Player::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
