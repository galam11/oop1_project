#include "Rail.h"
#include "macros.h"
#include <SFML/Graphics.hpp>

Rail::Rail(const sf::Vector2f& position)
	: GameObject(RAIL, position)
{
}