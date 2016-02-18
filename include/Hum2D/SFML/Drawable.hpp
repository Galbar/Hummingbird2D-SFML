#ifndef H2D_DRAWABLE_HPP
#define H2D_DRAWABLE_HPP
#include <SFML/Graphics.hpp>
#include "Hum2D/Hum2D.hpp"

namespace h2d
{
class Drawable : public Behaviour
{
public:
    Drawable();
    ~Drawable();

    virtual void init() override;
    virtual void onDestroy() override;

    void enable();
    void disable();
    bool isEnabled() const;

    virtual sf::Drawable* sfDrawable() =0;
    virtual sf::Transformable* sfTransformable();
    const sf::Shader* shader() const;
    void setShader(const sf::Shader* shader);

    const Transformation& transform() const;
    Transformation& transform();

private:
    bool p_is_enabled;
    Transformation p_transform;
    const sf::Shader* p_shader;
};
}
#endif
