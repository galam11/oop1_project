#include "AssetsManager.h"
#include "macros.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

AssetsManager AssetsManager::m_instance = AssetsManager();

AssetsManager& AssetsManager::instance()
{
    return m_instance;
}

AssetsManager::AssetsManager()
{
    m_textures[PLAYER] = loadTexture("player.png");
    m_textures[ENEMY] = loadTexture("enemy.png");
    m_textures[COIN] = loadTexture("coin.png");
    m_textures[FLOOR] = loadTexture("floor.png");
    m_textures[BREAKABLE_FLOOR] = loadTexture("breakable_floor.png");
    m_textures[LADDER] = loadTexture("ladder.png");
    m_textures[RAIL] = loadTexture("rail.png");

	m_errTexture = loadTexture("error.png");
}

const sf::Texture& AssetsManager::getTexture(const char id) const
{
    auto it = m_textures.find(id);
    if (it != m_textures.end())
        return (it->second);
    return m_errTexture;
}

// temp
const sf::SoundBuffer* AssetsManager::getSoundBuffer(const char id) const
{
    auto it = m_soundBuffers.find(id);
    if (it != m_soundBuffers.end())
        return &(it->second);
    return nullptr;
}

sf::Texture AssetsManager::loadTexture(const std::string& filename)
{
    sf::Texture temp;
    if (!temp.loadFromFile(filename)) 
    {
        std::cerr << "Error loading :" << filename << std::endl;
    }
    return temp;
}

sf::SoundBuffer AssetsManager::loadSoundBuffer(const std::string& filename)
{
    sf::SoundBuffer temp;
    if (!temp.loadFromFile(filename))
    {
        std::cerr << "Error loading :" << filename << std::endl;
    }
    return temp;
}