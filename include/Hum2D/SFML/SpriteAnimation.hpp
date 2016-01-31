#ifndef H2D_SPRITE_ANIMATION_HPP
#define H2D_SPRITE_ANIMATION_HPP
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Hum2D/Time.hpp"
#include "Hum2D/ResourceManager.hpp"

namespace h2d
{
struct SpriteAnimation
{
    sf::Texture* texture;
    int offset_x, offset_y, margin_x, margin_y, width, height;
    std::vector<unsigned int> frame_order;
    std::vector<Time> frame_time;
};
class SpriteAnimationManager : public ResourceManager<SpriteAnimation, std::string, SpriteAnimation>
{
    SpriteAnimation* loadResource(const SpriteAnimation& animation) override;
};
}
#endif
