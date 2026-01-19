#include "HideableGameObject.h"

bool HideableGameObject::isHidden() const
{
	return m_hidden;
}

void HideableGameObject::draw(sf::RenderWindow& window) const
{
	if (!m_hidden)
		window.draw(m_sprite);
}

HideableGameObject::HideableGameObject(char type, const sf::Vector2f& position)
	: GameObject(type, position) { }

