#include "Enemy.h"
#include "macros.h"
#include "Board.h"
#include "PathFinder.h"

Enemy::Enemy(const sf::Vector2f& position, const Player& player, const Board& board) :
	MovableGameObject(ENEMY, position),
	m_player(player),
	m_board(board)
{
	m_speed = 300.f;
}

void Enemy::handleColliton(GameObject& other) { other.handleColliton(*this); }

sf::Vector2f Enemy::updateMovingGameobject(const sf::Time& dt)
{
	sf::Vector2i start(getGlobalBounds().getCenter().x / GO_TEXTURE_DIMANTION,
		getGlobalBounds().getCenter().y / GO_TEXTURE_DIMANTION);
	sf::Vector2i target(m_player.getPositon().x / GO_TEXTURE_DIMANTION,
		m_player.getPositon().y / GO_TEXTURE_DIMANTION);

	sf::Vector2i nextStep = PathFinder::findNextStep(start, target, m_board);

	if (nextStep == start)
		return m_player.getPositon() - getGlobalBounds().getCenter();

	sf::Vector2f targetPixelPos((float)nextStep.x * GO_TEXTURE_DIMANTION + (GO_TEXTURE_DIMANTION / 2.f),
		(float)nextStep.y * GO_TEXTURE_DIMANTION + (GO_TEXTURE_DIMANTION / 2.f));

	return targetPixelPos - getGlobalBounds().getCenter();
}

