#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Player.h"

class LevelScene : public Scene
{
public:
	LevelScene();
	~LevelScene();
	void update(const sf::Time& dt) override;
	void onKeyPressed(const sf::Event::KeyPressed& event) override;
	void onKeyReleased(const sf::Event::KeyReleased& event) override;

	void display(sf::RenderWindow& window) const override;

private:
	std::vector<MovableGameObject*> m_movableGameObjects;
};