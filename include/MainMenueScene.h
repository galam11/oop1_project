#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
class MainMenuScene : public Scene
{
public:
	void update(const sf::Time& dt) override;
	void display(sf::RenderWindow& window) const override;

};