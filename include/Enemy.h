#pragma once
#include <SFML/Graphics.hpp>
#include "MovableGameObject.h"
#include "macros.h"
#include "Player.h"
#include "Animator.h"

class Board;

class Enemy : public MovableGameObject
{
public:
	Enemy(const sf::Vector2f& position, const Player& player, const Board& board);

	sf::Vector2f updateMovingGameobject(const sf::Time& dt) override;

	void setTarget(const sf::Vector2f& newTarget);

	void handleColliton(GameObject& other) override;

protected:
	// Enemies must complete climbs before moving horizontally
	bool canJumpOffClimbables() const override { return false; }

private:
	sf::Vector2f m_target;
	const Player& m_player;
	const Board& m_board;
};