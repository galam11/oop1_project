#include "GameObject.h"


void GameObject::draw(sf::RenderWindow& window) const { }

void GameObject::update(const sf::Time& time) { }

bool GameObject::collidedWith(const GameObject& other)
{
	return getGlobalBounds().findIntersection(other.getGlobalBounds()).has_value();
}

void GameObject::handleColliton(Rail& other) {}

void GameObject::handleColliton(Player& other) {}

void GameObject::handleColliton(Ladder& other) {}

void GameObject::handleColliton(Floor& other) {}

void GameObject::handleColliton(Enemy& other) {}

void GameObject::handleColliton(Coin& other) {}

void GameObject::handleColliton(BreakableFloor& other) {}

