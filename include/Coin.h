#pragma once
#include "GameObject.h"
#include "HideableGameObject.h"
#include <SFML/Graphics.hpp>

class Player;

class Coin : public HideableGameObject
{
public:
	Coin(const sf::Vector2f& position);
	
	void handleColliton(GameObject& other) override;

	void handleColliton(const Player& other);
};