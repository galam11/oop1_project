#pragma once
#include <SFML/Graphics.hpp>

class Animator
{
public:
	Animator(sf::Sprite& spright, int fps = 10);
	void animate(const sf::Time& dt);
	void setAnimation(int anim);
	void setFramePerSecend(float timePerFrame);
	void resetAnimation();
	bool animationOnLastFrame();
private:
	sf::Sprite& m_sprite;
	int m_frame = 0;
	int m_animation = 0;
	float m_time = 0;
	float m_timePerFrame = 1.f;
	const int m_totalFrames;
};