#pragma once
#include <sfml/Graphics.hpp>
#include "Player.h"
#include "Board.h"
class Hud
{
public:
	Hud(const Player& player, const sf::Clock& timer, const Board& totalTime);

	void dispaly(sf::RenderWindow& window) const;
	void update();

private:
	const Player& m_player;
	const sf::Clock& m_timer;
	const Board& m_board;


	sf::RectangleShape m_backround;
	sf::Text m_LevelText;
	sf::Text m_LivesText;
	sf::Text m_TimerText;
};