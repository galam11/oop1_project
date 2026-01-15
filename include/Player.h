#pragma once
#include "MovableGameObject.h"

class Floor;

class Player : public MovableGameObject
{
public:
	Player(const sf::Vector2f& position = sf::Vector2f());

	void update(const sf::Time& dt) override;

	int getCoins() const;
	int getScore() const;
	void increseCoins();
	void increseScore(int amount);

	void handleColliton(GameObject& other) override;

	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPositon() const;

	void handleColliton(const Floor& other) override;
	void handleColliton(const Enemy& other) override;
	
private:
	int m_score;
	int m_coins;
};