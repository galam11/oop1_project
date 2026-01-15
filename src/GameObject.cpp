#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "AssetsManager.h"

#include "Rail.h"
#include "Player.h"
#include "Ladder.h"
#include "Floor.h"
#include "Enemy.h"
#include "Coin.h"
#include "BreakableFloor.h"

GameObject::GameObject(char type, const sf::Vector2f& positon)
	 : m_sprite(AssetsManager::instance().getTexture(type)) 
{ 
	m_sprite.setPosition(positon);
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

bool GameObject::collidedWith(const GameObject& other)
{
	return m_sprite.getGlobalBounds()
		.findIntersection(other.m_sprite.getGlobalBounds()).has_value();
}

void GameObject::setPosition(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
}

sf::Vector2f GameObject::getPositon() const
{
	return m_sprite.getPosition();
}

void GameObject::handleColliton(const Rail& other)
{
}

void GameObject::handleColliton(const Player& other)
{
}

void GameObject::handleColliton(const Ladder& other)
{
}

void GameObject::handleColliton(const Floor& other)
{
}

void GameObject::handleColliton(const Enemy& other)
{
}

void GameObject::handleColliton(const Coin& other)
{
}

void GameObject::handleColliton(const BreakableFloor& other)
{
}