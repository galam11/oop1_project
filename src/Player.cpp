#include "Player.h"
#include "macros.h"
#include "Enemy.h"
#include "BreakableFloor.h"
#include "AssetsManager.h"

const float DIG_OFFSET_VERTICAL = 90.0f;
const float DIG_OFFSET_HORIZANTAL = 110.0f;

Player::Player(const sf::Vector2f& position) :
	MovableGameObject(PLAYER, position),
	m_coinSound(AssetsManager::instance().getSoundBuffer(SoundID::COIN_PICKUP)),
	m_digSound(AssetsManager::instance().getSoundBuffer(SoundID::DIGGING)),
	m_deathSound(AssetsManager::instance().getSoundBuffer(SoundID::DEATH))
{
	m_speed = 400.f;
}

void Player::update(const sf::Time& dt)
{
	MovableGameObject::update(dt);

	// Sync marks AFTER movement so the next collision phase detects the correct floor
	if (m_leftMark) m_leftMark->follow(*this);
	if (m_rightMark) m_rightMark->follow(*this);
}

sf::Vector2f Player::updateMovingGameobject(const sf::Time& dt)
{
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) && !m_justPresdZ)
	{
		if (auto floorPtr = m_leftMark->takeHitFloor())
		{
			floorPtr->remove();
			m_digSound.play();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X) && !m_justPresdX)
	{
		if (auto floorPtr = m_rightMark->takeHitFloor())
		{
			floorPtr->remove();
			m_digSound.play();
		}
	}

	m_justPresdX = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X);
	m_justPresdZ = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z);

	return dir;
}

sf::Vector2f Player::getPositon() const { return getGlobalBounds().getCenter(); }

void Player::handleColliton(Enemy& other)
{
	if (!m_gotHit) {
		m_lives--;
		m_gotHit = true;
		m_deathSound.play();
	}
}

void Player::handleColliton(Coin& other)
{
	m_score += 2 * m_currentLevel;
	m_coinSound.play();
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

int Player::getScore() const { return m_score; }
int Player::getLives() const { return m_lives; }
int Player::getCurrentLevel() const { return m_currentLevel; }
bool Player::gotHit() const { return m_gotHit; }
void Player::handleColliton(GameObject& other) { other.handleColliton(*this); }