#pragma once
#include "GameObject.h"

class HideableGameObject : public GameObject
{
public:
	bool isHidden() const;

	void draw(sf::RenderWindow& window) const override;

	
protected:
	HideableGameObject(char type, const sf::Vector2f& position);
	bool m_hidden = false;
};
