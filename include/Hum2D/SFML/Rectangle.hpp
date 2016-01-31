#ifndef H2D_RECTANGLE_DRAWABLE_HPP
#define H2D_RECTANGLE_DRAWABLE_HPP
#include "Drawable.hpp"

namespace h2d
{
class Rectangle : public Drawable
{
public:
    Rectangle(const sf::Vector2f& size, const sf::Color& fill_color);
    sf::Drawable* sfDrawable() override;
    sf::Transformable* sfTransformable() override;
    sf::RectangleShape& rectangle();
    const sf::RectangleShape& rectangle() const;

    static const char* behaviourName();

    private:
    sf::RectangleShape p_rectangle;
};
}
#endif
