#include "Scene.h"
#include "AssetsManager.h"


Scene::Scene(const std::string& boardFilePath, SoundID soundId) : 
	m_board(boardFilePath),
	m_sceneSound(AssetsManager::instance().getSoundBuffer(soundId)) { }

Scene::~Scene() = default;

void Scene::update(const sf::Time& dt)
{
	if (m_sceneSound.getStatus() == sf::SoundSource::Status::Stopped)
		AssetsManager::instance().setMusicVolume(100.f);
	
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