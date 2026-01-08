#include "Scene.h"

void Scene::display(sf::RenderWindow& window) const
{
	for (const auto& gameObject : m_gameObjects)
	{
		gameObject->draw(window);
	}
}

Scene::~Scene()
{
	for (auto& gameObject : m_gameObjects)
	{
		delete gameObject;
	}
	m_gameObjects.clear();
}