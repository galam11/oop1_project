#include "Coin.h"
#include "macros.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>


const float RTOTATE_CHANCE = 0.008f;

int Coin::s_CoinCount = 0;

int Coin::getCoinCount()
{
	return s_CoinCount;
}

Coin::Coin(const sf::Vector2f& position)
	: RemovableGameObject(COIN, position) 
{
	m_animator.setAnimation(1);
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
	auto f = ((rand() % 1000 + 1) / 1000.f);

	if (m_animator.animationOnLastFrame())
	{
		m_animator.setAnimation(1);
		m_animator.resetAnimation();
		m_animator.setFramePerSecend(1.f);
	}

	else if ( f < RTOTATE_CHANCE)
	{
		m_animator.setAnimation(0);
		m_animator.setFramePerSecend(10.f);
	}


	m_animator.animate(dt);
}
