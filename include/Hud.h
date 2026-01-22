#pragma once
#include <sfml/Graphics.hpp>
#include <Player.h>
class Hud
{
public:
	Hud(const Player& player, const sf::Clock& timer, sf::Time totalTime); 

	void dispaly(sf::RenderWindow& window) const;

private:
	const Player& m_player;
	const sf::Clock& m_timer;
	const sf::Time m_totalTime;

	sf::RectangleShape m_backround;
	sf::Text m_text;
};