#include "Board.h"
#include "macros.h"

#include "AssetsManager.h"
#include <iostream>

#include "Player.h"
#include "Enemy.h"
#include "Coin.h"
#include "Rail.h"
#include "Ladder.h"
#include "BreakableFloor.h"
#include "Floor.h"

Board::Board()
{
	m_file.open("Board.txt");
	if (!m_file.is_open())
	{
		std::cerr << "Failed to open Board.txt" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Board::update(const sf::Time& dt)
{
	m_player.update(dt);

	for (const auto& movableObject : m_movableObjects)
		movableObject->update(dt);

	collisions();
}

void Board::display(sf::RenderWindow& window) const
{
	window.setView(m_boardView);

	for (const auto& obj : m_gameObjects)
		obj->draw(window);
	
	for (const auto& mobObj : m_movableObjects)
		mobObj->draw(window);
	
	m_player.draw(window);

	window.setView(window.getDefaultView());
}



bool Board::loadNextLevel()
{
	if (!m_file.is_open() || m_file.eof()) return false;

	m_movableObjects.clear();
	m_gameObjects.clear();

	int rows = 0;
	m_file >> rows;
	if (m_file.fail()) return false;

	std::string line;
	std::getline(m_file, line);

	// Get tile dimensions (default to 50 if texture fails)
	sf::Vector2u textureSize = AssetsManager::instance().getTexture(FLOOR).getSize();
	float tileH = static_cast<float>(textureSize.y);
	float tileW = static_cast<float>(textureSize.x);
	if (tileH == 0) tileH = 50.0f;
	if (tileW == 0) tileW = 50.0f;

	for (int i = 0; i < rows; ++i)
	{
		std::getline(m_file, line);

		if (i == 0)
		{
			m_boardSize.x = line.size() * tileW;
			m_boardSize.y = rows * tileH;
		}

		for (size_t j = 0; j < line.size(); ++j)
			createGameObject(line[j], sf::Vector2f(j * tileW, i * tileH));

	}

	m_boardView.setSize(m_boardSize);
	m_boardView.setCenter(m_boardSize * 0.5f);

	return true;
}

void Board::createGameObject(char type, const sf::Vector2f& position)
{
	switch (type)
	{
	case PLAYER:
		m_player.setPosition(position);
		break;
	case ENEMY:
		m_movableObjects.push_back(std::make_unique<Enemy>(position, m_player));
		break;
	case COIN:
		m_gameObjects.push_back(std::make_unique<Coin>(position));
		break;
	case FLOOR:
		m_gameObjects.push_back(std::make_unique<Floor>(position));
		break;
	case BREAKABLE_FLOOR:
		m_gameObjects.push_back(std::make_unique<BreakableFloor>(position));
		break;
	case LADDER:
		m_gameObjects.push_back(std::make_unique<Ladder>(position));
		break;
	case RAIL:
		m_gameObjects.push_back(std::make_unique<Rail>(position));
		break;
	}
}

void Board::collisions()
{
	GameObject& playerRef = m_player;

	// player with game objects
	for (const auto& other : m_gameObjects)
		if (m_player.collidedWith(*other))
		{
			playerRef.handleColliton(*other);
			other->handleColliton(playerRef);
		}

	//player with movable objects
	for (const auto& other : m_movableObjects)
		if (m_player.collidedWith(*other))
		{
			playerRef.handleColliton(*other);
			other->handleColliton(playerRef);
		}
	
	// game objects with movable objects
	for (const auto& movableObject : m_movableObjects)
		for (const auto& gameObject : m_gameObjects)
			if (movableObject->collidedWith(*gameObject))
			{
				movableObject->handleColliton(*gameObject);
				gameObject->handleColliton(*movableObject);
			}
}
