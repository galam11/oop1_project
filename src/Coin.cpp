#include "Coin.h"
#include "macros.h"
#include <SFML/Graphics.hpp>

Coin::Coin(const sf::Vector2f& position)
	: HideableGameObject(COIN, position)
{
}

void Coin::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}

void Coin::handleColliton(const Player& other)
{
	m_hidden = true;
}
