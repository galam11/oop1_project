#pragma once
#include "GameObject.h"
#include "MovableGameObject.h"
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

class Board
{
public:
	Board();

	bool loadNextLevel(std::vector<GameObject*>& staticObjects,
		std::vector<MovableGameObject*>& movableObjects,
		sf::Vector2f& boardSize);

private:
	std::ifstream m_file;
};