#pragma once
#include "MovableGameObject.h"

class Player : public MovableGameObject
{
public:
	Player(const sf::Vector2f& position = sf::Vector2f());

	void update(const sf::Time& dt) override;

	int getCoins() const;
	int getScore() const;
	int getLives() const;
	bool gotHit() const;
	void handleColliton(GameObject& other) override;

	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPositon() const;

	void handleColliton(const Enemy& other) override;
	
private:
	int m_score = 0;
	int m_coins = 0;
	int m_lives = 3;

	bool m_gotHit = false;
};