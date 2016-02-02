#include "Rectangle.hpp"
using namespace h2d;

Rectangle::Rectangle(const sf::Vector2f& size, const sf::Color& fill_color):
p_rectangle(size)
{
p_rectangle.setFillColor(fill_color);
}

sf::Drawable* Rectangle::sfDrawable()
{
    return &p_rectangle;
}

sf::Transformable* Rectangle::sfTransformable()
{
    return &p_rectangle;
}

sf::RectangleShape& Rectangle::rectangle()
{
    return p_rectangle;
}

const sf::RectangleShape& Rectangle::rectangle() const
{
    return p_rectangle;
}

const char* Rectangle::behaviourName()
{
    return "h2d::Rectangle";
}
