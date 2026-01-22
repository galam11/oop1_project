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

const sf::Vector2f UP = { 0.f, -1.f };
const sf::Vector2f DOWN = { 0.f, 1.f };
const sf::Vector2f LEFT = { -1.f, 0.f };
const sf::Vector2f RIGHT = { 1.f, 0.f };
const sf::Vector2f VEC2_ZERO = { 1.f, 0.f };

const float GRAVITY = 3.5f;