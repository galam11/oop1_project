#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <map>
#include <string>

#include "macros.h"

class AssetsManager {
public:
	~AssetsManager() = default;

	static AssetsManager& instance();
	const sf::Texture& getTexture(const ID id) const;
	const sf::SoundBuffer& getSoundBuffer(const SoundID id) const;
	const sf::Font& getFont() const;

	void playMusic();
	void setMusicVolume(float volume);

private:
	AssetsManager();
	AssetsManager(const AssetsManager&) = default;
	AssetsManager& operator=(const AssetsManager&) = default;
	static AssetsManager m_instance;

	sf::Texture loadTexture(const std::string& filename);
	sf::SoundBuffer loadSoundBuffer(const std::string& filename);

	std::map<ID, sf::Texture> m_textures;
	std::map<SoundID, sf::SoundBuffer> m_soundBuffers;

	sf::Texture m_errTexture;
	sf::Font m_font;
	sf::Music m_bgMusic;
};