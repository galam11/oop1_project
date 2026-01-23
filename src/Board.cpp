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
	m_player.update();

	for (const auto& movableObject : m_movableObjects)
		movableObject->update();

	

	m_player.updatePositon(dt);

	for (const auto& movableObject : m_movableObjects)
		movableObject->updatePositon(dt);

	handleCollisions();
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

const Player& Board::getPlayer() const
{
	return m_player;
}

bool Board::isInBounds(const sf::Vector2f vec) const
{
	return !(vec.x > m_boardSize.x || vec.x < 0 || vec.y > m_boardSize.y || vec.y < 0);
}

sf::Time Board::getTimeOut() const
{
	return m_levelTime;
}

bool Board::loadNextLevel()
{
	if (!loadRawBoard())
		return false;
	
	m_player.nextLevel();
	loadFromRawBoard();
	return true;
}

void Board::Reset()
{
	m_player.resetGameObject();
	for (const auto& mobObj : m_movableObjects)
		mobObj->resetGameObject();
}
 
void Board::loadFromRawBoard()
{
	m_movableObjects.clear();
	m_gameObjects.clear();
	m_player.resetPlayerHealth();

	sf::Vector2u textureSize = AssetsManager::instance().getTexture(FLOOR).getSize();
	float tileH = static_cast<float>(textureSize.y);
	float tileW = static_cast<float>(textureSize.x);
	if (tileH == 0) tileH = 50.0f;
	if (tileW == 0) tileW = 50.0f;

	m_boardSize.x = m_rawBoard[0].size() * tileW;
	m_boardSize.y = m_rawBoard.size() * tileH;

	for (int i = 0; i < m_rawBoard.size(); ++i)
		for (int j = 0; j < m_rawBoard[0].size(); ++j)
			createGameObject((Types)m_rawBoard[i][j], sf::Vector2f(j * tileW, i * tileH));

	m_boardView.setSize(m_boardSize);
	m_boardView.setCenter(m_boardSize * 0.5f);
}

bool Board::loadRawBoard()
{
	m_rawBoard.clear();
	if (!m_file.is_open() || m_file.eof()) 
	{
		std::cout << "file not open or eof" << std::endl;
		return false;
	}

	int rows = 0;
	m_file >> rows;
	if (m_file.fail())
	{
		std::cout << "Fail at reading first int" << std::endl;
		return false;
	}

	int minits, sec;
	m_file >> minits >> sec;
	m_levelTime = sf::seconds(minits * 60 + sec);


	std::string line;
	std::getline(m_file, line);


	for (int i = 0; i < rows; ++i)
	{
		std::getline(m_file, line);
		m_rawBoard.push_back(line);
	}

	return true;
}

void Board::createGameObject(Types type, const sf::Vector2f& position)
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

void Board::handleCollisions()
{
	GameObject& playerRef = m_player;
	for (const auto& gameObject : m_gameObjects)
		if (gameObject->collidedWith(playerRef))
		{
			gameObject->handleColliton(playerRef);
			playerRef.handleColliton(*gameObject);
		}

	for (const auto& movableObject : m_movableObjects)
		if (movableObject->collidedWith(playerRef))
		{
			movableObject->handleColliton(playerRef);
			playerRef.handleColliton(*movableObject);
		}

	// game objects with movable objects
	for (const auto& movableObject : m_movableObjects)
		for (const auto& gameObject : m_gameObjects)
			if (movableObject->collidedWith(*gameObject))
			{
				movableObject->handleColliton(*gameObject);
				gameObject->handleColliton(*movableObject);
			}


	std::erase_if(m_gameObjects, [](const std::unique_ptr<GameObject>& item) 
	{
		if (auto ptr = dynamic_cast<RemovableGameObject*>(item.get()))
			return ptr->isToBeRemoved();
		return false;
	});
}
