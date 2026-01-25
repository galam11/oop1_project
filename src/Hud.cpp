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
	m_playerSpright(AssetsManager::instance().getTexture(PLAYER_SINGLE))
{ 
	
	float width = ((float)WINDOW_SIZE.x);

	m_LivesText.setPosition({ width * 0.06f , 25.f });
	m_TimerText.setPosition({ width * 0.5f  , 25.f });
	m_LevelText.setPosition({ width * 0.93f , 25.f });


	m_playerSpright.scale({ 0.4f, 0.5f });
	m_playerSpright.setPosition(m_LivesText.getPosition() - sf::Vector2f(60.f, 10.f));
}

void Hud::dispaly(sf::RenderWindow& window) const
{
	window.draw(m_LevelText);
	window.draw(m_TimerText);
	window.draw(m_LivesText);
	window.draw(m_playerSpright);
}

void Hud::update()
{
	m_TimerText.setOrigin(m_LivesText.getLocalBounds().size * 0.5f);

	m_LivesText.setString(std::string("Lives x ") + std::to_string(m_player.getLives()));

	auto timeLeft = (m_board.getTimeOut() - m_timer.getElapsedTime()).asSeconds();
	auto min = (int)(timeLeft / 60);
	auto sec = (int)timeLeft % 60;

	m_TimerText.setString(std::string("Time Left: ") + std::to_string(min) + ":" + std::to_string(sec));

	m_LevelText.setString(std::string("Level: ") + std::to_string(m_player.getCurrentLevel()) +
		"\nScore: " + std::to_string(m_player.getScore() ));
}
