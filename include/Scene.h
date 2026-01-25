#pragma once
#include <SFML/Graphics.hpp>
#include <Board.h>
#include <vector>
#include <memory>

class Scene
{
public:

	Scene() = default;
	virtual ~Scene() = default;

	virtual void update(const sf::Time& dt) = 0;
	virtual void display(sf::RenderWindow& window) const = 0;

	virtual void onKeyPressed(const sf::Event::KeyPressed& event);
	virtual void onKeyReleased(const sf::Event::KeyReleased& event);
	

	bool isSceneFinished() const;
	std::unique_ptr<Scene>& getNextSeane();

protected:
	Board m_board;
	std::unique_ptr<Scene> m_nextSeane = nullptr;
};