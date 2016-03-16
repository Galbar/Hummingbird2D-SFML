#ifndef H2D_SPRITE_HPP
#define H2D_SPRITE_HPP
#include "Drawable.hpp"

namespace h2d
{
class Sprite : public Drawable
{
public:
    Sprite(const sf::Texture& texture);
    Sprite(const sf::Texture& texture, const sf::IntRect& rectangle);
    sf::Drawable* sfDrawable() override;
    sf::Transformable* sfTransformable() override;
    sf::Sprite& sprite();
    const sf::Sprite& sprite() const;

    static const char* behaviorName();

private:
    sf::Sprite p_sprite;
};
}
#endif
