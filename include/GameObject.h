#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window) const;

protected:
	GameObject(char type, const sf::Vector2f& position);
	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPositon() const;

private:
	sf::Sprite m_sprite;
};