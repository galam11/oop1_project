#include "Hud.h"
#include "AssetsManager.h"
#include "macros.h"

Hud::Hud(const Player& player, const sf::Clock& timer, sf::Time totalTime) :
	m_player(player), 
	m_timer(timer), 
	m_totalTime(totalTime),
	m_text(AssetsManager::instance().getFont()),
	m_backround({ (float)WINDOW_SIZE.x , 60.f })
{ 
	m_backround.setFillColor(sf::Color::Blue);
	m_text.setPosition({ 20.f, 15.f });
	m_text.setString("Hello world");
}

void Hud::dispaly(sf::RenderWindow& window) const
{
	window.draw(m_backround);
	window.draw(m_text);
}
