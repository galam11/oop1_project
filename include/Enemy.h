#pragma once
#include <SFML/Graphics.hpp>
#include "MovableGameObject.h"
#include "macros.h"

#include "Player.h"

class Enemy : public MovableGameObject
{
public:
	Enemy(const sf::Vector2f& position, const Player& player);

	void update(const sf::Time& dt) override;

	void setTarget(const sf::Vector2f& newTarget);

private:
	sf::Vector2f m_target;
	const Player& m_player;
};