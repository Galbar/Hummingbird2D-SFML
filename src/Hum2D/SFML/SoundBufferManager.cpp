#include "SoundBufferManager.hpp"

sf::SoundBuffer* h2d::SoundBufferManager::loadResource(const std::string& name)
{
    sf::SoundBuffer* resource = new sf::SoundBuffer();
    if (not resource->loadFromFile(name))
        return nullptr;
    return resource;
}
