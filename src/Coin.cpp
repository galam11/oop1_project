#include "Coin.h"
#include "macros.h"
#include <SFML/Graphics.hpp>

Coin::Coin(const sf::Vector2f& position)
	: GameObject(COIN, position)
{
}

void Coin::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}
