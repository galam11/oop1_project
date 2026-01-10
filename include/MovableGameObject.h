#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class MovableGameObject : public GameObject
{
public:
	MovableGameObject(char type, const sf::Vector2f& position);

	virtual void update() = 0;
	virtual void onKeyPressed(const sf::Event::KeyPressed& event);
	virtual void onKeyReleased(const sf::Event::KeyReleased& event);


	void updatePositon(const sf::Time& dt);

	// New method to reset to starting position
	void resetPosition();

	sf::Vector2f getMoveDirection() const;
protected:
	sf::Vector2f m_moveDirection = { 0, 0 };
	float m_speed = 1.0f;

	// Store the initial position
	sf::Vector2f m_startPosition;
};