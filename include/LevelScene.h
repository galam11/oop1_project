#pragma once
#include "Scene.h"
class LevelScene : public Scene
{

public:
	void update() override;
	void onKeyPressed(const sf::Event::KeyPressed& event) override;
	void onKeyReleased(const sf::Event::KeyReleased& event) override;
	void display(sf::RenderWindow& window) const override;

};