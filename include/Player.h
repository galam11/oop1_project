#pragma once
#include "MovableGameObject.h"

class Player : public MovableGameObject
{
public:
	Player(const sf::Vector2f& position);

	void update() override;

	void onKeyPressed(const sf::Event::KeyPressed& event) override;
	void onKeyReleased(const sf::Event::KeyReleased& event) override;

	int getCoins();
	int getScore();
	void increseCoins();
	void increseScore(int amount);

private:
	int m_score;
	int m_coins;

};