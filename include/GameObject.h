#pragma once
#include <SFML/Graphics.hpp>


class GameObject
{
public:
	bool CollidedWith(const GameObject& other) const;
	virtual void draw(sf::RenderWindow& window) const;
private:
	sf::Sprite m_Sprite;
};