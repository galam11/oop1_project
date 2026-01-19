#pragma once
#include <SFML/Graphics.hpp>
enum Types
{
	PLAYER			= '@',
	ENEMY			= '%',
	COIN			= '*',
	FLOOR			= '#',
	BREAKABLE_FLOOR	= '^',
	LADDER			= 'H',
	RAIL			= '-',
	EMPTY			= ' '
};

const sf::Vector2f WINDOW_SIZE = { 800.f, 600.f };

const sf::Vector2 UP = { 0.f, -1.f };
const sf::Vector2 DOWN = { 0.f, 1.f };
const sf::Vector2 LEFT = { -1.f, 0.f };
const sf::Vector2 RIGHT = { 1.f, 0.f };

const float GRAVITY = 5.f;