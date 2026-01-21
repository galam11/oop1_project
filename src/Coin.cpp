#include "Coin.h"
#include "macros.h"
#include <SFML/Graphics.hpp>


int Coin::s_CoinCount = 0;

int Coin::getCoinCount()
{
	return s_CoinCount;
}

Coin::Coin(const sf::Vector2f& position)
	: RemovableGameObject(COIN, position) 
{
	s_CoinCount++;
}

Coin::~Coin()
{
	s_CoinCount--;
}

void Coin::handleColliton(GameObject& other)
{
	other.handleColliton(*this);
}

void Coin::handleColliton(const Player& other)
{
	m_isToBeRemoved = true;
}
