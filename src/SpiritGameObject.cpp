#include "SpiritGameObject.h"
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

SpiritGameObject::SpiritGameObject(ID type, const sf::Vector2f& positon) : 
	m_sprite(AssetsManager::instance().getTexture(type)) , 
	m_animator(m_sprite)
{ 
	m_sprite.setPosition(positon);
}

void SpiritGameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

sf::FloatRect SpiritGameObject::getGlobalBounds() const { return m_sprite.getGlobalBounds(); }

void SpiritGameObject::moveMe(const sf::Vector2f& pos) { m_sprite.move(pos); }

void SpiritGameObject::setMyPosition(const sf::Vector2f& position) { m_sprite.setPosition(position); }
