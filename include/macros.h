#pragma once
#include <string>
#include <SFML/Graphics.hpp>

enum ID
{
	PLAYER = '@',
	PLAYER_SINGLE,
	ENEMY = '%',
	ENEMY_SINGLE,
	COIN = '*',
	COIN_SINGLE,
	FLOOR = '#',
	BREAKABLE_FLOOR = '^',
	LADDER = 'H',
	RAIL = '-',
	EMPTY = ' ',
	BACKROUND
};

enum SoundID
{
	COIN_PICKUP,
	DIGGING,
	DEATH,
	LEVEL_VICTORY,
	VICTORY,
	FAILURE
};

const sf::Vector2u WINDOW_SIZE = { 1600, 900 };

const sf::Vector2f UP = { 0.f, -1.f };
const sf::Vector2f DOWN = { 0.f, 1.f };
const sf::Vector2f LEFT = { -1.f, 0.f };
const sf::Vector2f RIGHT = { 1.f, 0.f };
const sf::Vector2f VEC2_ZERO = { 0.f, 0.f };

const float GRAVITY = 900.f;

const int GO_TEXTURE_DIMANTION = 128;

const std::string BORAD_FILE_PATH = "Board.txt";
const std::string MENUE_BORAD_FILE_PATH = "MenueBoard.txt";

const std::string TITLE_TEXT = "LODE RUNNER";
const std::string RULES_TEXT = "Rules:\n- Collect all coins \n- Avoid enemies \n- Go up and down on ladders\n- Go left or right on rails\n\nPress Enter to return";
const std::string WIN_TEXT = "VICTORY!";
const std::string LOOS_TEXT = "GAME OVER";
const std::string SCORE_SHOWCASE_TEXT = "Final Score: ";

const int TITLE_FONT_SIZE = 150;
const int LARG_FONT_SIZE = 100;
const int FORNT_SIZE = 50;
