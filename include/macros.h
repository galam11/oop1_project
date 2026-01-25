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
const sf::Vector2f VEC2_ZERO = { 0.f, 0.f };

const float GRAVITY = 900.f;

const int GO_TEXTURE_DIMANTION = 128;
//  debug stuff

#define Debug(x) " | "<< #x << ": "<< (x)
