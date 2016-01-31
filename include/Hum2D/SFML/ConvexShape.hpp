#ifndef H2D_CONVEX_SHAPE_DRAWABLE_HPP
#define H2D_CONVEX_SHAPE_DRAWABLE_HPP
#include <vector>
#include "Drawable.hpp"

namespace h2d
{
class ConvexShape : public Drawable
{
public:
    ConvexShape(const std::vector<sf::Vector2f>& points, const sf::Color& fill_color);
    sf::Drawable* sfDrawable() override;
    sf::Transformable* sfTransformable() override;
    sf::ConvexShape& convexShape();
    const sf::ConvexShape& convexShape() const;

    static const char* behaviourName();

    private:
    sf::ConvexShape p_convex_shape;
};
}
#endif
