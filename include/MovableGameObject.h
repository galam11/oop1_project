#pragma once
#include "SpriteGameObject.h"
#include <SFML/Graphics.hpp>

enum ID;

class MovableGameObject : public SpriteGameObject
{
public:
	MovableGameObject(ID type, const sf::Vector2f& position);

	virtual void update(const sf::Time& dt) override;

	void reset() override;
	sf::FloatRect getGlobalBounds() const override;

	virtual void handleColliton(GameObject& other) override = 0;
	void handleColliton(Floor& other) override;
	void handleColliton(BreakableFloor& other) override;
	void handleColliton(Ladder& other) override;
	void handleColliton(Rail& other) override;

protected:
	float m_speed = 1.0f;
	sf::Vector2f m_startPosition;

	bool isOnLadder() const;
	bool isOnRail() const;

private:
	virtual sf::Vector2f updateMovingGameobject(const sf::Time& dt) = 0;

	void updatePositon(const sf::Time& dt);
	void animate(const sf::Time& dt);
	void handleSolidCollision(const SpriteGameObject& other);

	sf::Vector2f m_moveDirctaion = VEC2_ZERO;

	bool m_onLadder = false;
	bool m_onRail = false;
	bool m_onGround = false;

	bool m_colidedWithRailLastFrame = false;
	bool m_colidedWithRail = false;
	bool m_ignoreRail = false;
};