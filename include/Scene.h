#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.h"
#include <vector>
#include <memory>
#include <optional>

class Scene
{
public:

	Scene(const std::string& boardFilePath = BORAD_FILE_PATH, SoundID soundId = SoundID::VICTORY);
	virtual ~Scene();

	virtual void update(const sf::Time& dt);
	virtual void display(sf::RenderWindow& window) const = 0;

	virtual void onKeyPressed(const sf::Event::KeyPressed& event);
	virtual void onKeyReleased(const sf::Event::KeyReleased& event);

	bool isSceneFinished() const;
	std::unique_ptr<Scene>& getNextSeane();

protected:
	Board m_board;
	sf::Sound m_sceneSound;
	std::unique_ptr<Scene> m_nextSeane = nullptr;
};