#include "Hud.h"
#include "AssetsManager.h"
#include "macros.h"

Hud::Hud(const Player& player, const sf::Clock& timer, const Board& board) :
	m_player(player), 
	m_timer(timer), 
	m_board(board),
	m_LevelText(AssetsManager::instance().getFont()),
	m_LivesText(AssetsManager::instance().getFont()),
	m_TimerText(AssetsManager::instance().getFont()),
	m_backround({ (float)WINDOW_SIZE.x , 60.f })
{ 
	m_backround.setFillColor(sf::Color::Blue);
	
	float width = ((float)WINDOW_SIZE.x) * 0.88f;

	m_LivesText.setPosition({ width * 0.1f , 15.f });
	m_TimerText.setPosition({ width * 0.5f , 15.f });
	m_LevelText.setPosition({ width * 0.9f , 15.f });

}

void Hud::dispaly(sf::RenderWindow& window) const
{
	window.draw(m_backround);
	
	window.draw(m_LevelText);
	window.draw(m_TimerText);
	window.draw(m_LivesText);
}

void Hud::update()
{
	m_LivesText.setString(std::string("Lives x ") + std::to_string(m_player.getLives()));
	m_TimerText.setString(
		std::string("Time Left: ") + std::to_string((int)(m_board.getTimeOut() - m_timer.getElapsedTime()).asSeconds())
	);
	m_LevelText.setString(std::string("Level: ") + std::to_string(m_player.getCurrentLevel()));
}
