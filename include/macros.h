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

const sf::Vector2u WINDOW_SIZE = { 1600, 900 };

const sf::Vector2 UP = { 0.f, -1.f };
const sf::Vector2 DOWN = { 0.f, 1.f };
const sf::Vector2 LEFT = { -1.f, 0.f };
const sf::Vector2 RIGHT = { 1.f, 0.f };

const float GRAVITY = 5.f;