#include "macros.h"
#include <SFML/Graphics.hpp>

sf::FloatRect scaleRectFromCenter(const sf::FloatRect& rect, float factorX, float factorY) {
    sf::Vector2f center = rect.position + (rect.size / 2.f);

    sf::Vector2f newSize(rect.size.x * factorX, rect.size.y * factorY);

    sf::Vector2f newPos = center - (newSize / 2.f);

    return sf::FloatRect(newPos, newSize);
}

sf::FloatRect scaleRectFromCenter(const sf::FloatRect& rect, float factor)
{
    return scaleRectFromCenter(rect, factor, factor);
}