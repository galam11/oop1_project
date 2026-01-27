#include "SpriteGameObject.h"
#include "SpriteGameObject.h"
#include <SFML/Graphics.hpp>

#include "macros.h"
#include "AssetsManager.h"

SpriteGameObject::SpriteGameObject(ID type, const sf::Vector2f& positon) : 
	m_sprite(AssetsManager::instance().getTexture(type)) , 
	m_animator(m_sprite)
{ 
	m_sprite.setPosition(positon);
}

void SpriteGameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

sf::FloatRect SpriteGameObject::getGlobalBounds() const { return m_sprite.getGlobalBounds(); }

void SpriteGameObject::moveMe(const sf::Vector2f& pos) { m_sprite.move(pos); }

void SpriteGameObject::setMyPosition(const sf::Vector2f& position) { m_sprite.setPosition(position); }

sf::FloatRect SpriteGameObject::scaleBoundingBoxFromCenter(float factorX, float factorY) const
{
    auto rect = SpriteGameObject::getGlobalBounds();

    sf::Vector2f center = rect.position + (rect.size / 2.f);

    sf::Vector2f newSize(rect.size.x * factorX, rect.size.y * factorY);

    sf::Vector2f newPos = center - (newSize / 2.f);

    return sf::FloatRect(newPos, newSize);
}

sf::FloatRect SpriteGameObject::scaleBoundingBoxFromCenter(float factor) const
{
    return scaleBoundingBoxFromCenter(factor, factor);
}