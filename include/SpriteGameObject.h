#pragma once
#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "macros.h"
#include "GameObject.h"


class Rail;
class Player;
class Ladder;
class Floor;
class Enemy;
class Coin;
class BreakableFloor;

class SpriteGameObject : public GameObject
{
public:
	SpriteGameObject(ID type, const sf::Vector2f& position);
	void draw(sf::RenderWindow& window) const override;
	sf::FloatRect getGlobalBounds() const override; 

private:
	sf::Sprite m_sprite;

protected:
	void moveMe(const sf::Vector2f& pos) override;
	void setMyPosition(const sf::Vector2f& position) override;

	sf::FloatRect scaleBoundingBoxFromCenter(float factorX, float factorY) const;
	sf::FloatRect scaleBoundingBoxFromCenter(float factor) const;

	Animator m_animator;
};