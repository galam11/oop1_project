#pragma once
#include "Scene.h"

class EndScreenScene : public Scene
{
	// Inherited via Scene
	void update(const sf::Time& dt) override;
	void display(sf::RenderWindow& window) const override;
};