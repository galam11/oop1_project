#include "LevelScene.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>


void LevelScene::update()
{
	// Update game objects and logic for the level scene
}

void LevelScene::display(sf::RenderWindow& window) const
{
	Scene::display(window);
	window.draw(rs);
}

void LevelScene::onKeyReleased(const sf::Event::KeyReleased& event)
{
	// Handle key released events specific to the level scene
}

void LevelScene::onKeyPressed(const sf::Event::KeyPressed& event)
{
	// Handle key pressed events specific to the level scene
}