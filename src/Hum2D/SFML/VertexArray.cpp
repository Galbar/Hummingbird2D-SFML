#include "VertexArray.hpp"
using namespace h2d;

VertexArray::VertexArray():
p_vertex_array()
{}

VertexArray::VertexArray(sf::PrimitiveType type, std::size_t vertexCount):
p_vertex_array(type, vertexCount)
{}

sf::Drawable* VertexArray::sfDrawable()
{
    return &p_vertex_array;
}

sf::VertexArray& VertexArray::vertexArray()
{
    return p_vertex_array;
}

const sf::VertexArray& VertexArray::vertexArray() const
{
    return p_vertex_array;
}
