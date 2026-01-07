#pragma once
#include "MovableGameObject.h"

class Player : public MovableGameObject
{
public:
	int getCoins();
	int getScore();

	void increseCoins();
	void increseScore(int amount);

private:
	int m_score;
	int m_coins;
};