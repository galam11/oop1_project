#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>
class LevelScene : public Scene
{
public:
	LevelScene() = default;

	void update() override;
	void display(sf::RenderWindow& window) const override;
	void onKeyPressed(const sf::Event::KeyPressed& event) override;
	void onKeyReleased(const sf::Event::KeyReleased& event) override;

private:
	sf::RectangleShape	rs;
};