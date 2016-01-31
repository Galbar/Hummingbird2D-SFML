#ifndef H2B_TEXTURE_MANAGER_HPP
#define H2B_TEXTURE_MANAGER_HPP
#include <SFML/Graphics.hpp>
#include "Hum2D/ResourceManager.hpp"

namespace h2d
{
class TextureManager : public ResourceManager<sf::Texture>
{
protected:
    sf::Texture* loadResource(const std::string& name) override;
};
}
#endif
