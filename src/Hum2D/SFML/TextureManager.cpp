#include "TextureManager.hpp"

sf::Texture* h2d::TextureManager::loadResource(const std::string& name)
{
    sf::Texture* resource = new sf::Texture();
    if (not resource->loadFromFile(name))
        return nullptr;
    return resource;
}
