#include "GameObject.h"
#include <SFML/Graphics.hpp>

#include "macros.h"
#include "AssetsManager.h"

#include "Rail.h"
#include "Player.h"
#include "Ladder.h"
#include "Floor.h"
#include "Enemy.h"
#include "Coin.h"
#include "BreakableFloor.h"

GameObject::GameObject(Types type, const sf::Vector2f& positon) : 
	m_sprite(AssetsManager::instance().getTexture(type))
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

sf::FloatRect GameObject::getGlobalBounds() const { return m_sprite.getGlobalBounds(); }

void GameObject::moveMe(const sf::Vector2f& pos) { m_sprite.move(pos); }

void GameObject::setMyPosition(const sf::Vector2f& position) { m_sprite.setPosition(position); }

void GameObject::handleColliton(const Rail& other){ }

void GameObject::handleColliton(const Player& other) { }

void GameObject::handleColliton(const Ladder& other) { }

void GameObject::handleColliton(const Floor& other) { }

void GameObject::handleColliton(const Enemy& other) { }

void GameObject::handleColliton(const Coin& other) { }

void GameObject::handleColliton(const BreakableFloor& other) { }

