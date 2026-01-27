#include "Animator.h"
#include "macros.h"
#include <iostream>

Animator::Animator(sf::Sprite& spirit, int fps) :
	m_sprite(spirit),
	m_totalFrames(spirit.getTexture().getSize().x / GO_TEXTURE_DIMANTION)
{
	setFramePerSecend(fps);

	m_sprite.setTextureRect(
		sf::IntRect(
			{0, 0} ,
			{GO_TEXTURE_DIMANTION, GO_TEXTURE_DIMANTION}
		)
	);
}


void Animator::animate(const sf::Time& dt)
{
	m_time += dt.asSeconds();

	if (m_time >= m_timePerFrame)
	{
		m_time = 0.f;
		m_frame = (m_frame + 1) % m_totalFrames;
		m_sprite.setTextureRect(
			{
				{ m_frame * GO_TEXTURE_DIMANTION, m_animation * GO_TEXTURE_DIMANTION } ,
				{ GO_TEXTURE_DIMANTION, GO_TEXTURE_DIMANTION }
			}
		);
	}
}

void Animator::setAnimation(int anim)
{ 
	m_animation = anim; 
}

void Animator::setFramePerSecend(float framePerSecend)
{
	if (framePerSecend > 0)
		m_timePerFrame = 1 / framePerSecend;
}

void Animator::resetAnimation()
{
	m_frame = 0;
	m_time = 0;
	m_sprite.setTextureRect(
		{
			{m_frame * GO_TEXTURE_DIMANTION, m_animation * GO_TEXTURE_DIMANTION} ,
			{ GO_TEXTURE_DIMANTION, GO_TEXTURE_DIMANTION }
		}
	);
}

bool Animator::animationOnLastFrame()
{
	return m_frame == m_totalFrames - 1;
}
