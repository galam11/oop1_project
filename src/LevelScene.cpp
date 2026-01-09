#include "LevelScene.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>
#include "macros.h"


LevelScene::LevelScene()
{
	m_movableGameObjects.push_back(new Player({ 50.f, 50.f }));
}

LevelScene::~LevelScene()
{
	for (const auto& gameObject : m_movableGameObjects)
		delete gameObject;
	m_movableGameObjects.clear();
}

void LevelScene::display(sf::RenderWindow& window) const
{
	Scene::display(window);

	for (const auto& gameObject : m_movableGameObjects)
		gameObject->draw(window);
}

void LevelScene::update(const sf::Time& dt)
{
	for (auto* obj : m_movableGameObjects)
		obj->update();

	// handle collision here

	for (auto* obj : m_movableGameObjects)
		obj->updatePositon(dt);
}


void LevelScene::onKeyReleased(const sf::Event::KeyReleased& event)
{
	for (auto* obj : m_movableGameObjects)
		obj->onKeyReleased(event);
}



void LevelScene::onKeyPressed(const sf::Event::KeyPressed& event)
{
	for (auto* obj : m_movableGameObjects)
		obj->onKeyPressed(event);
}