#pragma once
#include "macros.h"

class Rail;
class Player;
class Ladder;
class Floor;
class Enemy;
class Coin;
class BreakableFloor;
class RemoveMark;

class GameObject
{
public:
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window) const;
	virtual void update(const sf::Time& time);
	virtual void reset();

	virtual void handleColliton(GameObject& other) = 0;
	virtual sf::FloatRect getGlobalBounds() const = 0;


	virtual void handleColliton(Rail& other);
	virtual void handleColliton(Player& other);
	virtual void handleColliton(Ladder& other);
	virtual void handleColliton(Floor& other);
	virtual void handleColliton(Enemy& other);
	virtual void handleColliton(Coin& other);
	virtual void handleColliton(BreakableFloor& other);
	virtual void handleColliton(RemoveMark& other);

	bool collidedWith(const GameObject& other);

protected:
	virtual void moveMe(const sf::Vector2f& pos) = 0;
	virtual void setMyPosition(const sf::Vector2f& position) = 0;
};