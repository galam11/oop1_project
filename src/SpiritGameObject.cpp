#include "SpiritGameObject.h"
#include <SFML/Graphics.hpp>

#include "macros.h"
#include "AssetsManager.h"

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

sf::FloatRect SpiritGameObject::scaleBoundingBoxFromCenter(float factorX, float factorY) const
{
    auto rect = SpiritGameObject::getGlobalBounds();

    sf::Vector2f center = rect.position + (rect.size / 2.f);

    sf::Vector2f newSize(rect.size.x * factorX, rect.size.y * factorY);

    sf::Vector2f newPos = center - (newSize / 2.f);

    return sf::FloatRect(newPos, newSize);
}

sf::FloatRect SpiritGameObject::scaleBoundingBoxFromCenter(float factor) const
{
    return scaleBoundingBoxFromCenter(factor, factor);
}