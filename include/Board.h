#pragma once
#include "SpriteGameObject.h"
#include "Player.h"
#include "MovableGameObject.h"
#include <memory>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "macros.h"

class Board
{
public:
	Board(const std::string& filePath);

	void update(const sf::Time& dt);
	void display(sf::RenderWindow& window) const;

	bool loadNextLevel();
	void loadFromRawBoard();
	void Reset();
	
	const Player& getPlayer() const;
	sf::Time getTimeOut() const;
	std::vector<sf::Vector2i> getValidNeighbors(const sf::Vector2i& node) const;

	bool isPlayerInBounds() const;
private:
	std::ifstream m_file;

	Player m_player;
	sf::View m_boardView;
	sf::Vector2f m_boardSize;
	sf::Time m_levelTime;

	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	std::vector<std::string> m_rawBoard;

	void handleCollisions();

	void createGameObject(ID type, const sf::Vector2f& position);
	void initPlayer(const sf::Vector2f& position);

	bool loadRawBoard();
	void calculateViewSize();

	char getTile(int r, int c) const;
	sf::Vector2u getGridSize() const;
	bool isWalkable(int r, int c) const;
};