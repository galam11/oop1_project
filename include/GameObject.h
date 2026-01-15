#pragma once
#include <SFML/Graphics.hpp>

class Rail;
class Player;
class Ladder;
class Floor;
class Enemy;
class Coin;
class BreakableFloor;

class GameObject
{
public:
	
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window) const;

	bool collidedWith(const GameObject& other);
	virtual void handleColliton(GameObject& other) = 0;

	virtual void handleColliton(const Rail& other);
	virtual void handleColliton(const Player& other);
	virtual void handleColliton(const Ladder& other);
	virtual void handleColliton(const Floor& other);
	virtual void handleColliton(const Enemy& other);
	virtual void handleColliton(const Coin& other);
	virtual void handleColliton(const BreakableFloor& other);

protected:
	GameObject(char type, const sf::Vector2f& position);
	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPositon() const;

private:
	sf::Sprite m_sprite;
};