#ifndef H2D_CIRCLE_DRAWABLE_HPP
#define H2D_CIRCLE_DRAWABLE_HPP
#include "Drawable.hpp"

namespace h2d
{
class Circle : public Drawable
{
public:
    Circle(double radius, const sf::Color& fill_color);
    sf::Drawable* sfDrawable() override;
    sf::Transformable* sfTransformable() override;
    sf::CircleShape& circle();
    const sf::CircleShape& circle() const;

    static const char* behaviourName();

private:
    sf::CircleShape p_circle;
};
}
#endif
