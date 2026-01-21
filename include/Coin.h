#pragma once
#include "GameObject.h"
#include "HideableGameObject.h"
#include <SFML/Graphics.hpp>

class Player;

class Coin : public RemovableGameObject
{
public:
	static int getCoinCount();

	Coin(const sf::Vector2f& position);
	~Coin();
	
	void handleColliton(GameObject& other) override;

	void handleColliton(const Player& other);

	
private:
	static int s_CoinCount;
};