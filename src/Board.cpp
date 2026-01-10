#include "Board.h"
#include "macros.h"
#include "Player.h"
#include "Enemy.h"
#include "AssetsManager.h"
#include <iostream>

Board::Board()
{
	m_file.open("Board.txt");
	if (!m_file.is_open())
	{
		std::cerr << "Failed to open Board.txt" << std::endl;
		exit(EXIT_FAILURE);
	}
}

bool Board::loadNextLevel(std::vector<GameObject*>& staticObjects,
	std::vector<MovableGameObject*>& movableObjects,
	sf::Vector2f& boardSize)
{
	if (!m_file.is_open() || m_file.eof()) return false;

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
			boardSize.x = line.size() * tileW;
			boardSize.y = rows * tileH;
		}

		for (size_t j = 0; j < line.size(); ++j)
		{
			char symbol = line[j];
			sf::Vector2f pos(j * tileW, i * tileH);

			if (symbol == EMPTY) continue;

			if (symbol == PLAYER)
				movableObjects.push_back(new Player(pos));
			else if (symbol == ENEMY)
				movableObjects.push_back(new Enemy(pos));
			else
				staticObjects.push_back(new GameObject(symbol, pos));
		}
	}
	return true;
}