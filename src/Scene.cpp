#include "Scene.h"

void Scene::onKeyPressed(const sf::Event::KeyPressed& event)
{

}


void Scene::onKeyReleased(const sf::Event::KeyReleased& event)
{

}

bool Scene::isSceneFinished() const
{
	return m_nextSeane != nullptr;
}

std::unique_ptr<Scene>& Scene::getNextSeane()
{
	return m_nextSeane;
}
