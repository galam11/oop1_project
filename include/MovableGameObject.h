#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>


enum Types;

class MovableGameObject : public GameObject
{
public:
	MovableGameObject(Types type, const sf::Vector2f& position);

	virtual void update(const sf::Time& dt) = 0;

	void resetGameObject() override;

	virtual void handleColliton(GameObject& other) override = 0;
	void handleColliton(const Floor& other) override;
	void handleColliton(const BreakableFloor& other) override;
	void handleColliton(const Ladder& other) override;
	void handleColliton(const Rail& other) override;
protected:
	float m_speed = 1.0f;
	sf::Vector2f m_startPosition;

	void updatePositon(sf::Vector2f moveVec,const sf::Time& dt);

	bool isOnLadder() const;
	bool isOnRail() const;
private:
	void handleSolidCollision(const GameObject& other);
	bool m_onLadder = false;
	bool m_onRail = false;
	bool m_onGround = false;
};