#include "GameObject.h"
#include <SFML/Graphics.hpp>

#include "AssetsManager.h"

GameObject::GameObject(char type, const sf::Vector2f& positon)
	 : m_sprite(AssetsManager::instance().getTexture(type)) 
{ 
	m_sprite.setPosition(positon);

	
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void GameObject::setPosition(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
}

sf::Vector2f GameObject::getPositon() const
{
	return m_sprite.getPosition();
}
