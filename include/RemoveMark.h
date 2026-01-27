#pragma once

#include <sfml/Graphics.hpp>
#include "GameObject.h"
#include "macros.h"

const const sf::Vector2f BOUNDS_SIZE = sf::Vector2f{ GO_TEXTURE_DIMANTION , GO_TEXTURE_DIMANTION } * 0.1f ;

class RemoveMark : public GameObject
{
public:
	void handleColliton(GameObject& other) override;
	sf::FloatRect getGlobalBounds() const override;

	void follow(const GameObject& other);
	void setOffset(sf::Vector2f offset);
	void handleColliton(BreakableFloor& other);

	BreakableFloor* takeHitFloor();
private:
	sf::FloatRect m_bounds = { {0, 0} , BOUNDS_SIZE };
	sf::Vector2f m_offset;
	BreakableFloor* m_hitFloor = nullptr;

	void update(const sf::Time& dt);
	void moveMe(const sf::Vector2f& pos) override;
	void setMyPosition(const sf::Vector2f& position) override;
};