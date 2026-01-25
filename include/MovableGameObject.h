#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>


enum ID;

class MovableGameObject : public GameObject
{
public:
	MovableGameObject(ID type, const sf::Vector2f& position);

	void update(const sf::Time& dt);
	

	void resetGameObject();

	virtual void handleColliton(GameObject& other) override = 0;
	void handleColliton(const Floor& other) override;
	void handleColliton(const BreakableFloor& other) override;
	void handleColliton(const Ladder& other) override;
	void handleColliton(const Rail& other) override;
protected:
	float m_speed = 1.0f;
	sf::Vector2f m_startPosition;
	

	bool isOnLadder() const;
	bool isOnRail() const;
private:
	virtual sf::Vector2f updateMovingGameobject(const sf::Time& dt) = 0;

	void updatePositon(const sf::Time& dt);
	void animate(const sf::Time& dt);
	void handleSolidCollision(const GameObject& other);
	sf::Vector2f m_moveDirctaion = VEC2_ZERO;

	bool m_onLadder = false;
	bool m_onRail = false;
	bool m_onGround = false;
};