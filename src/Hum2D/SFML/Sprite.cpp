#include "Sprite.hpp"
using namespace h2d;

Sprite::Sprite(const sf::Texture& texture):
p_sprite(texture)
{}

Sprite::Sprite(const sf::Texture& texture, const sf::IntRect& rectangle):
p_sprite(texture, rectangle)
{}

sf::Drawable* Sprite::sfDrawable()
{
    return &p_sprite;
}

sf::Transformable* Sprite::sfTransformable()
{
    return &p_sprite;
}

sf::Sprite& Sprite::sprite()
{
    return p_sprite;
}

const sf::Sprite& Sprite::sprite() const
{
    return p_sprite;
}

const char* Sprite::behaviourName()
{
    return "h2d::Sprite";
}
