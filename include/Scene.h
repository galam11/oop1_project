#pragma once
#include <SFML/Graphics.hpp>
#include <Board.h>
#include <vector>

class Scene
{
public:

	Scene() = default;
	virtual ~Scene() = default;

	virtual void update(const sf::Time& dt) = 0;
	virtual void onKeyPressed(const sf::Event::KeyPressed& event);
	virtual void onKeyReleased(const sf::Event::KeyReleased& event);
	virtual void display(sf::RenderWindow& window) const = 0;

protected:
	Board m_board;
};