#pragma once
#include "MovableGameObject.h"
#include "Animator.h"
#include "RemoveMark.h"
#include <SFML/Audio.hpp>
#include <optional>

class Enemy;
class Coin;

class Player : public MovableGameObject
{
public:
	Player(const sf::Vector2f& position = sf::Vector2f());

	sf::Vector2f updateMovingGameobject(const sf::Time& dt) override;

	int getScore() const;
	int getLives() const;
	int getCurrentLevel() const;
	bool gotHit() const;
	void handleColliton(GameObject& other) override;

	sf::Vector2f getPositon() const;

	void handleColliton(Enemy& other) override;
	void handleColliton(Coin& other) override;

	void initPlayer(const sf::Vector2f& position, RemoveMark* rightMark, RemoveMark* leftMark);
	void nextLevel();

private:
	RemoveMark* m_rightMark = nullptr;
	RemoveMark* m_leftMark = nullptr;

	int m_score = 0;
	int m_currentLevel = 0;
	int m_lives = 3;
	bool m_gotHit = false;

	sf::Sound m_coinSound;
	sf::Sound m_digSound;
	sf::Sound m_deathSound;
};