#pragma once
#include "GameObject.h"

enum Types;
class HideableGameObject : public GameObject
{
public:
	bool isHidden() const;

	void draw(sf::RenderWindow& window) const override;

	void resetGameObject() override;
	
protected:
	HideableGameObject(Types type, const sf::Vector2f& position);
	bool m_hidden = false;
};
