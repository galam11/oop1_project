#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>


enum Types;

class MovableGameObject : public GameObject
{
public:
	MovableGameObject(Types type, const sf::Vector2f& position);

	virtual void update(const sf::Time& dt) = 0;

	void resetPosition();

	sf::Vector2f getMoveDirection() const;
	virtual void handleColliton(GameObject& other) override = 0;
	void handleColliton(const Floor& other) override;
	void handleColliton(const BreakableFloor& other) override;
	void handleColliton(const Ladder& other) override;
	void handleColliton(const Rail& other) override;
protected:
	sf::Vector2f m_moveDirection = { 0, 0 };
	float m_speed = 1.0f;

	sf::Vector2f m_startPosition;

	void updatePositon(const sf::Time& dt);

	bool isOnLadder() const;
	bool isOnRail() const;
private:
	void handleSolidCollision(const GameObject& other);
	bool m_onLadder = false;
	bool m_onRail = false;
	bool m_onGround = false;
};