#include "Circle.hpp"
using namespace h2d;

Circle::Circle(double radius, const sf::Color& fill_color):
h2d::Drawable(),
p_circle(radius)
{
p_circle.setFillColor(fill_color);
}

sf::Drawable* Circle::sfDrawable()
{
    return &p_circle;
}

sf::Transformable* Circle::sfTransformable()
{
    return &p_circle;
}

sf::CircleShape& Circle::circle()
{
    return p_circle;
}

const sf::CircleShape& Circle::circle() const
{
    return p_circle;
}

const char* Circle::behaviourName()
{
    return "h2d::Circle";
}
