#include "Text.hpp"
using namespace h2d;

Text::Text(const std::string& string, const sf::Font& font, unsigned int character_size):
p_text(string, font, character_size)
{}

sf::Drawable* Text::sfDrawable()
{
    return &p_text;
}

sf::Transformable* Text::sfTransformable()
{
    return &p_text;
}

sf::Text& Text::text()
{
    return p_text;
}

const sf::Text& Text::text() const
{
    return p_text;
}

const char* Text::behaviorName()
{
    return "h2d::Text";
}
