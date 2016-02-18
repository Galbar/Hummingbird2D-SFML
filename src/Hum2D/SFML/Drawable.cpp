#include "Drawable.hpp"
#include "SFMLPlugin.hpp"
using namespace h2d;

Drawable::Drawable():
p_is_enabled(true),
p_shader(nullptr)
{}

Drawable::~Drawable()
{}

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

const Transformation& Drawable::transform() const
{
    return p_transform;
}

Transformation& Drawable::transform()
{
    return p_transform;
}

const sf::Shader* Drawable::shader() const
{
    return p_shader;
}

void Drawable::setShader(const sf::Shader* shader)
{
    p_shader = shader;
}
