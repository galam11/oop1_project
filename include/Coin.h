#pragma once
#include "SpiritGameObject.h"
#include "RemovableGameObject.h"
#include <SFML/Graphics.hpp>

class Player;

class Coin : public RemovableGameObject
{
public:
	static int getCoinCount();

	Coin(const sf::Vector2f& position);
	~Coin();
	
	void handleColliton(GameObject& other) override;

	void handleColliton(Player& other);

	void update(const sf::Time& dt) override;
	
private:
	static int s_CoinCount;
};