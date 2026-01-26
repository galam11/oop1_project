#include "Scene.h"
#include "AssetsManager.h"

Scene::Scene() = default;
Scene::~Scene() = default;

void Scene::update(const sf::Time& dt)
{
	if (m_sceneSound.has_value() && m_sceneSound->getStatus() == sf::SoundSource::Status::Stopped)
	{
		AssetsManager::instance().setMusicVolume(100.f);
	}
}

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