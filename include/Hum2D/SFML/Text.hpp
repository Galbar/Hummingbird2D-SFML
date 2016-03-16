#ifndef H2D_TEXT_DRAWABLE_HPP
#define H2D_TEXT_DRAWABLE_HPP
#include "Drawable.hpp"

namespace h2d
{
class Text : public Drawable
{
public:
    Text(const std::string& string, const sf::Font& font, unsigned int character_size=30);
    sf::Drawable* sfDrawable() override;
    sf::Transformable* sfTransformable() override;
    sf::Text& text();
    const sf::Text& text() const;

    static const char* behaviorName();

private:
    sf::Text p_text;
};
}
#endif
