#include "Coin.h"
#include "macros.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>


int Coin::s_CoinCount = 0;

int Coin::getCoinCount()
{
	return s_CoinCount;
}

Coin::Coin(const sf::Vector2f& position)
	: RemovableGameObject(COIN, position) 
{
	m_animator.setFramePerSecend(7.f); // change here to set fps
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

void Coin::handleColliton(Player& other)
{
	m_isToBeRemoved = true;
}

void Coin::update(const sf::Time& dt)
{
	m_animator.animate(dt);
}

sf::FloatRect Coin::getGlobalBounds() const
{
	return scaleRectFromCenter(SpiritGameObject::getGlobalBounds(), .2f);
}
