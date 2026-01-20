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
	for (const auto& movableObject : m_movableObjects)
		movableObject->update(dt);

}

void Board::display(sf::RenderWindow& window) const
{
	window.setView(m_boardView);

	for (const auto& obj : m_gameObjects)
		obj->draw(window);
	
	for (const auto& mobObj : m_movableObjects)
		mobObj->draw(window);

	window.setView(window.getDefaultView());
}

const Player& Board::getPlayer() const
{
	return *m_player;
}

bool Board::isInBounds(const sf::Vector2f vec) const
{
	return !(vec.x > m_boardSize.x || vec.x < 0 || vec.y > m_boardSize.y || vec.y < 0);
}

bool Board::loadNextLevel()
{
	if (!m_file.is_open() || m_file.eof()) return false;

	m_movableObjects.clear();
	m_gameObjects.clear();

	m_movableObjects.push_back(std::make_unique<Player>());
	m_player = (Player*)m_movableObjects.back().get();

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
			createGameObject((Types)line[j], sf::Vector2f(j * tileW, i * tileH));

	}

	m_boardView.setSize(m_boardSize);
	m_boardView.setCenter(m_boardSize * 0.5f);

	return true;
}

void Board::softReset()
{
	for (const auto& mobObj : m_movableObjects)
		mobObj->resetGameObject();
}
 
void Board::reset()
{
	softReset();
	m_player->resetPlayer();
	for (const auto& obj : m_gameObjects)
		obj->resetGameObject();
}

void Board::createGameObject(Types type, const sf::Vector2f& position)
{
	switch (type)
	{
	case PLAYER:
		m_player->setPosition(position);
		break;
	case ENEMY:
		m_movableObjects.push_back(std::make_unique<Enemy>(position, *m_player));
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

void Board::handleCollisions()
{
	for (int i = 0; i < m_movableObjects.size(); i++)
		for (int j = i + 1; j < m_movableObjects.size(); j++)
		{
			const auto& movableObjectA = m_movableObjects[i];
			const auto& movableObjectB = m_movableObjects[j];

			if (movableObjectA->collidedWith(*movableObjectB))
			{
				movableObjectA->handleColliton(*movableObjectB);
				movableObjectB->handleColliton(*movableObjectA);
			}
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
