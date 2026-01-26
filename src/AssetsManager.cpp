#include "AssetsManager.h"
#include "macros.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>

AssetsManager AssetsManager::m_instance = AssetsManager();

AssetsManager& AssetsManager::instance() { return m_instance; }

AssetsManager::AssetsManager()
{
	m_textures[PLAYER] = loadTexture("player_spright_sheet.png");
	m_textures[PLAYER_SINGLE] = loadTexture("player.png");

	m_textures[ENEMY] = loadTexture("enemy_sheet.png");
	m_textures[ENEMY_SINGLE] = loadTexture("enemy.png");

	m_textures[COIN] = loadTexture("coin_sheet.png");
	m_textures[COIN_SINGLE] = loadTexture("coin.png");

	m_textures[FLOOR] = loadTexture("floor.png");
	m_textures[BREAKABLE_FLOOR] = loadTexture("breakable_floor.png");
	m_textures[LADDER] = loadTexture("ladder.png");
	m_textures[RAIL] = loadTexture("rail.png");

	m_errTexture = loadTexture("error.png");

	if (!m_font.openFromFile("jersey10-Regular.ttf"))
		std::cout << "Error loading font" << std::endl;

	m_soundBuffers[SoundID::COIN_PICKUP] = loadSoundBuffer("coin_pickup.wav");
	m_soundBuffers[SoundID::DIGGING] = loadSoundBuffer("digging.wav");
	m_soundBuffers[SoundID::DEATH] = loadSoundBuffer("death.wav");
	m_soundBuffers[SoundID::LEVEL_VICTORY] = loadSoundBuffer("level_victory.wav");
	m_soundBuffers[SoundID::VICTORY] = loadSoundBuffer("victory_sound.wav");
	m_soundBuffers[SoundID::FAILURE] = loadSoundBuffer("failure_sound.wav");

	if (!m_bgMusic.openFromFile("background_music.mp3"))
		std::cout << "Error loading music" << std::endl;

	m_bgMusic.setLooping(true);
}

const sf::Texture& AssetsManager::getTexture(const ID id) const
{
	auto it = m_textures.find(id);
	if (it != m_textures.end())
		return (it->second);

	return m_errTexture;
}

const sf::Font& AssetsManager::getFont() const { return m_font; }

const sf::SoundBuffer& AssetsManager::getSoundBuffer(const SoundID id) const
{
	return m_soundBuffers.at(id);
}

void AssetsManager::playMusic()
{
	if (m_bgMusic.getStatus() != sf::SoundSource::Status::Playing)
		m_bgMusic.play();
}

void AssetsManager::setMusicVolume(float volume)
{
	m_bgMusic.setVolume(volume);
}

sf::Texture AssetsManager::loadTexture(const std::string& filename)
{
	sf::Texture temp;
	if (!temp.loadFromFile(filename))
		std::cerr << "Error loading texture: " << filename << std::endl;

	return temp;
}

sf::SoundBuffer AssetsManager::loadSoundBuffer(const std::string& filename)
{
	sf::SoundBuffer temp;
	if (!temp.loadFromFile(filename))
		std::cerr << "Error loading sound: " << filename << std::endl;

	return temp;
}