#include "Scene.h"

void Scene::display(sf::RenderWindow& window) const
{
	for (const auto& gameObject : m_gameObjects)
		gameObject->draw(window);
	
}

Scene::~Scene()
{
	for (auto& gameObject : m_gameObjects)
		delete gameObject;
	
	m_gameObjects.clear();
}

void Scene::onKeyPressed(const sf::Event::KeyPressed& event)
{

}


void Scene::onKeyReleased(const sf::Event::KeyReleased& event)
{

}