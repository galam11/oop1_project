#include "Player.h"
#include "macros.h"
#include "Enemy.h"
#include "Board.h"
#include "BreakableFloor.h"
#include <iostream>

const int DIG_OFFSET_VERTICAL = 90;
const int DIG_OFFSET_HORIZANTAL = 110;

Player::Player(const sf::Vector2f& position) : 
	MovableGameObject(PLAYER, position)
{
	m_speed = 400.f;
}

sf::Vector2f Player::updateMovingGameobject(const sf::Time& dt)
{
	m_leftMark->follow(*this);
	m_rightMark->follow(*this);

	m_gotHit = false;
	sf::Vector2f dir = { 0.f, 0.f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && isOnLadder())
		dir += UP;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		dir += DOWN;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		dir += RIGHT;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		dir += LEFT;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
		if (auto floorPtr = m_leftMark->takeHitFloor())
			floorPtr->remove();
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
		if (auto floorPtr = m_rightMark->takeHitFloor())
			floorPtr->remove();

	return dir;
}

sf::Vector2f Player::getPositon() const
{
	return getGlobalBounds().getCenter();
}

void Player::handleColliton(Enemy& other)
{
	if (!m_gotHit)
	{
		m_lives--;
		m_gotHit = true;
	}
}

void Player::handleColliton(Coin& other)
{
	m_score += 2 * m_currentLevel;
}

void Player::initPlayer(const sf::Vector2f& position, RemoveMark* rightMark, RemoveMark* leftMark)
{
	m_startPosition = position;

	setMyPosition(position);

	m_rightMark = rightMark;
	m_rightMark->setOffset({ DIG_OFFSET_HORIZANTAL , DIG_OFFSET_VERTICAL });
	m_leftMark = leftMark;
	m_leftMark->setOffset({ -DIG_OFFSET_HORIZANTAL , DIG_OFFSET_VERTICAL });
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
