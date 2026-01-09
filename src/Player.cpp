#include "Player.h"
#include "macros.h"
Player::Player(const sf::Vector2f& position)
	: MovableGameObject(PLAYER, position), m_score(0), m_coins(0)
{
	m_speed = 200.f;
}

void Player::update()
{
	m_moveDirection = { 0.f, 0.f };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		m_moveDirection += UP;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		m_moveDirection += DOWN;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		m_moveDirection += RIGHT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		m_moveDirection += LEFT;
}

void Player::onKeyPressed(const sf::Event::KeyPressed& event)
{
	//switch (event.code)
	//{
	//	case sf::Keyboard::Key::Left: 
	//		m_moveDirection.x = -1;
	//		break;
	//	case sf::Keyboard::Key::Right:
	//		m_moveDirection.x = 1;
	//		break;
	//	case sf::Keyboard::Key::Up:
	//		m_moveDirection.y = -1;
	//		break;
	//	case sf::Keyboard::Key::Down:
	//		m_moveDirection.y = 1;
	//		break;
	//}
}

void Player::onKeyReleased(const sf::Event::KeyReleased& event)
{
	//switch (event.code)
	//{
	//case sf::Keyboard::Key::Left:
	//	m_moveDirection.x = 0;
	//	break;
	//case sf::Keyboard::Key::Right:
	//	m_moveDirection.x = 0;
	//	break;
	//case sf::Keyboard::Key::Up:
	//	m_moveDirection.y = 0;
	//	break;
	//case sf::Keyboard::Key::Down:
	//	m_moveDirection.y = 0;
	//	break;
	//}
}


int Player::getCoins()
{
	return m_coins;
}

int Player::getScore()
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