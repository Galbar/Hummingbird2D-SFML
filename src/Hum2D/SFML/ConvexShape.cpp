#include "ConvexShape.hpp"
using namespace h2d;

ConvexShape::ConvexShape(const std::vector<sf::Vector2f>& points, const sf::Color& fill_color):
p_convex_shape(points.size())
{
    for (unsigned int i = 0; i < points.size(); ++i)
    {
        p_convex_shape.setPoint(i, points[i]);
    }
    p_convex_shape.setFillColor(fill_color);
}

sf::Drawable* ConvexShape::sfDrawable()
{
    return &p_convex_shape;
}

sf::Transformable* ConvexShape::sfTransformable()
{
    return &p_convex_shape;
}

sf::ConvexShape& ConvexShape::convexShape()
{
    return p_convex_shape;
}

const sf::ConvexShape& ConvexShape::convexShape() const
{
    return p_convex_shape;
}

const char* ConvexShape::behaviorName()
{
    return "h2d::ConvexShape";
}
