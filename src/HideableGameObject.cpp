#include "HideableGameObject.h"
#include "macros.h"

bool HideableGameObject::isHidden() const
{
	return m_hidden;
}

void HideableGameObject::draw(sf::RenderWindow& window) const
{
	if (!m_hidden)
		GameObject::draw(window);
}

void HideableGameObject::resetGameObject()
{
	m_hidden = false;
}

HideableGameObject::HideableGameObject(Types type, const sf::Vector2f& position)
	: GameObject(type, position) { }

