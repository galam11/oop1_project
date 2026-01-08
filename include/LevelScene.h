#pragma once
#include "Scene.h"
class LevelScene : public Scene
{
public:
	LevelScene();

	void update() override;
	void onKeyPressed(const sf::Event::KeyPressed& event) override;
	void onKeyReleased(const sf::Event::KeyReleased& event) override;
};