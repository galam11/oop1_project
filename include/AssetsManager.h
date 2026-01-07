#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <string>

class AssetsManager
{
    ~AssetsManager() = default;

    static AssetsManager& instance();
    const sf::Texture*
 getTexture(const char id) const;
    const sf::SoundBuffer* getSoundBuffer(const char id) const;

private:
    AssetsManager();
    AssetsManager(const AssetsManager&) = default;
    AssetsManager& operator=(const AssetsManager&) = default;
    static AssetsManager m_instance;


    sf::Texture loadTexture(const std::string& filename);
    sf::SoundBuffer loadSoundBuffer(const std::string& filename);


    std::map<char, sf::Texture> m_textures;
    std::map<char, sf::SoundBuffer> m_soundBuffers;
};