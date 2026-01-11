#pragma once
#include "MovableGameObject.h"

class Player : public MovableGameObject
{
public:
	Player(const sf::Vector2f& position);

	void update() override;

	int getCoins() const;
	int getScore() const;
	void increseCoins();
	void increseScore(int amount);

private:
	int m_score;
	int m_coins;

};