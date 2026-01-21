#pragma once
#include <SFML/Graphics.hpp>
#include "macros.h"

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
	GameObject(Types type, const sf::Vector2f& position);
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window) const;

	virtual void resetGameObject();

	bool collidedWith(const GameObject& other);
	virtual void handleColliton(GameObject& other) = 0;

	virtual void handleColliton(const Rail& other);
	virtual void handleColliton(const Player& other);
	virtual void handleColliton(const Ladder& other);
	virtual void handleColliton(const Floor& other);
	virtual void handleColliton(const Enemy& other);
	virtual void handleColliton(const Coin& other);
	virtual void handleColliton(const BreakableFloor& other);

	sf::FloatRect getGlobalBounds() const;

protected:
	void moveMe(const sf::Vector2f& pos);
	void setMyPosition(const sf::Vector2f& position);

private:
	sf::Sprite m_sprite;	
};