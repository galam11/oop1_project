#pragma once
#include "MovableGameObject.h"

class Enemy;
class Coin;

class Player : public MovableGameObject
{
public:
	Player(const sf::Vector2f& position = sf::Vector2f());

	void update() override;

	int getScore() const;
	int getLives() const;
	int getCurrentLevel() const;
	bool gotHit() const;
	void handleColliton(GameObject& other) override;

	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPositon() const;

	void handleColliton(const Enemy& other) override;
	void handleColliton(const Coin& other) override;
	
	void resetPlayerHealth();

	void nextLevel();
private:
	int m_score = 0;
	int m_currentLevel = 0;
	int m_lives = 3;
	bool m_gotHit = false;
};