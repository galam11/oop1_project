#pragma once
#include "GameObject.h"
#include "Player.h"
#include "MovableGameObject.h"
#include <memory>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

class Board
{
public:
	Board();

	bool loadNextLevel();

	void update(const sf::Time& dt);
	void display(sf::RenderWindow& window) const;

private:
	std::ifstream m_file;
	int m_currentLevel = 0;

	sf::View m_boardView;
	sf::Vector2f m_boardSize;

	Player m_player;
	std::vector<std::unique_ptr<MovableGameObject>> m_movableObjects;
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;


	void createGameObject(char type, const sf::Vector2f& position);

	void collisions();
	
};

