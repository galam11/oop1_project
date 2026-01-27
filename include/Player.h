#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MovableGameObject.h"
#include "macros.h"
#include "RemoveMark.h"

class Player : public MovableGameObject
{
public:
	Player(const sf::Vector2f& position = { 0,0 });

	sf::Vector2f updateMovingGameobject(const sf::Time& dt) override;

	void handleColliton(GameObject& other) override;
	void handleColliton(Enemy& other) override;
	void handleColliton(Coin& other) override;

	void initPlayer(const sf::Vector2f& position, RemoveMark* rightMark, RemoveMark* leftMark);
	void nextLevel();

	int getScore() const;
	int getLives() const;
	int getCurrentLevel() const;
	bool gotHit() const;

	sf::Vector2f getPositon() const;

private:
	int m_lives = 3;
	int m_score = 0;
	int m_currentLevel = 0;
	bool m_gotHit = false;

	bool m_justPresdX = false;
	bool m_justPresdZ = false;

	RemoveMark* m_rightMark = nullptr;
	RemoveMark* m_leftMark = nullptr;

	sf::Sound m_coinSound;
	sf::Sound m_digSound;
	sf::Sound m_deathSound;
};