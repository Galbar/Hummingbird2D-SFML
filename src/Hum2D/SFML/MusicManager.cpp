#include "MusicManager.hpp"

sf::Music* h2d::MusicManager::loadResource(const std::string& name)
{
    sf::Music* resource = new sf::Music();
    if (not resource->openFromFile(name))
        return nullptr;
    return resource;
}
