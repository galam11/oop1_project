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
	m_moveDirection = { 0.f, 0.f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && isOnLadder())
		m_moveDirection += UP;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		m_moveDirection += DOWN;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		m_moveDirection += RIGHT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		m_moveDirection += LEFT;

	updatePositon(dt);
}

void Player::resetGameObject()
{
	m_sprite.setPosition(m_startPosition);
	m_gotHit = false;
}

void Player::resetPlayer()
{
	m_lives = 3;
}

void Player::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);

	//sf::Text info();
}

void Player::setPosition(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
	m_startPosition = position;
}

sf::Vector2f Player::getPositon() const
{
	return m_sprite.getGlobalBounds().getCenter();
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
