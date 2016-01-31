#include "Hum2D/Game.hpp"
#include "Hum2D/Actor.hpp"
#include "Hum2D/Transformation.hpp"
#include "Drawable.hpp"
#include "SFMLPlugin.hpp"
using namespace h2d;

Drawable::Drawable():
p_is_enabled(true),
p_transform(new Transformation),
p_shader(nullptr)
{}

Drawable::~Drawable()
{
    delete p_transform;
}

void Drawable::init()
{
    if (p_is_enabled)
    {
        actor().game().getPlugin<SFMLPlugin>()->addDrawable(this);
    }
}

void Drawable::onDestroy()
{
    disable();
}

void Drawable::enable()
{
    if (not p_is_enabled)
    {
        actor().game().getPlugin<SFMLPlugin>()->addDrawable(this);
        p_is_enabled = true;
    }
}
void Drawable::disable()
{
    if (p_is_enabled)
    {
        actor().game().getPlugin<SFMLPlugin>()->removeDrawable(this);
        p_is_enabled = false;
    }
}
bool Drawable::isEnabled() const
{
    return p_is_enabled;
}

sf::Transformable* Drawable::sfTransformable()
{
    return nullptr;
}

//sf::Sprite* Drawable::animatedSpriteUpdate()
//{
//    return nullptr;
//}

//sf::Shape* Drawable::shape()
//{
//    return nullptr;
//}

//sf::Sprite* Drawable::sprite()
//{
//    return nullptr;
//}

//sf::Text* Drawable::text()
//{
//    return nullptr;
//}

//sf::VertexArray* Drawable::vertexArray()
//{
//    return nullptr;
//}

const Transformation& Drawable::transform() const
{
    return *p_transform;
}

Transformation& Drawable::transform()
{
    return *p_transform;
}

const sf::Shader* Drawable::shader() const
{
    return p_shader;
}

void Drawable::setShader(const sf::Shader* shader)
{
    p_shader = shader;
}
