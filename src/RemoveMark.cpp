#include "RemoveMark.h"

void RemoveMark::handleColliton(GameObject& other)
{
    other.handleColliton(*this);
}

sf::FloatRect RemoveMark::getGlobalBounds() const
{
    return m_bounds;
}

void RemoveMark::update(const sf::Time& dt)
{
    m_hitFloor = nullptr;
}

void RemoveMark::follow(const GameObject& other)
{
    setMyPosition(other.getGlobalBounds().getCenter() + m_offset);
}

void RemoveMark::setOffset(sf::Vector2f offset)
{
    m_offset = offset;
}

void RemoveMark::handleColliton(BreakableFloor& other)
{
    m_hitFloor = &other;
}

BreakableFloor* RemoveMark::takeHitFloor()
{
    auto hit = m_hitFloor;
    m_hitFloor = nullptr;
    return hit;
}

void RemoveMark::moveMe(const sf::Vector2f& pos)
{
    m_bounds.position += pos;
}

void RemoveMark::setMyPosition(const sf::Vector2f& position)
{
    m_bounds.position = position;
}
