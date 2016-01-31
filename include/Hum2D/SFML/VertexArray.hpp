#ifndef H2D_VERTEX_ARRAY_DRAWABLE_HPP
#define H2D_VERTEX_ARRAY_DRAWABLE_HPP
#include "Drawable.hpp"

namespace h2d
{
class VertexArray : public Drawable
{
public:
    VertexArray();
    VertexArray(sf::PrimitiveType type, std::size_t vertexCount = 0);
    sf::Drawable* sfDrawable() override;
    sf::VertexArray& vertexArray();
    const sf::VertexArray& vertexArray() const;

private:
    sf::VertexArray p_vertex_array;
};
}
#endif
