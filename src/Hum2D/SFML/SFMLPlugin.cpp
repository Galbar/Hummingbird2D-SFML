#include <map>
#include "Hum2D/Hum2D.hpp"
#include "SFMLPlugin.hpp"
#include "InputHandler.hpp"
#include "TextureManager.hpp"
#include "SpriteAnimation.hpp"
#include "SoundBufferManager.hpp"
#include "MusicManager.hpp"
#include "Drawable.hpp"
using namespace h2d;

SFMLPlugin::SFMLPlugin(int window_width, int window_height, std::string window_title):
p_window_width(window_width),
p_window_height(window_height),
p_window_title(window_title)
{
    p_input = new InputHandler;
    p_texture_manager = new TextureManager;
    p_sprite_animation_manager = new SpriteAnimationManager;
    p_music_manager = new MusicManager;
    p_soundbuff_manager = new SoundBufferManager;
}

SFMLPlugin::~SFMLPlugin()
{
    delete p_input;
    delete p_texture_manager;
    delete p_music_manager;
    delete p_soundbuff_manager;
    delete p_sprite_animation_manager;
}

sf::RenderWindow& SFMLPlugin::window()
{
    return *p_window;
}

const sf::RenderWindow& SFMLPlugin::window() const
{
    return *p_window;
}

void SFMLPlugin::gameStart()
{
    p_window = new sf::RenderWindow(sf::VideoMode(p_window_width, p_window_height), p_window_title);
}

void SFMLPlugin::preFixedUpdate()
{
    p_input->update();
    sf::Event event;
    while (p_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            p_window->close();
            game().setRunning(false);
        }
        p_input->handleEvent(event);
        p_event_list.push_back(event);
    }
}

void SFMLPlugin::postFixedUpdate()
{
    p_event_list.clear();
}

void SFMLPlugin::postUpdate()
{
    p_window->clear();
    std::multimap<double, std::pair<const sf::Drawable*, const sf::Shader*>> draw_order;
    for (Drawable* drawable : p_drawable_set)
    {
        sf::Drawable* sf_drawable = drawable->sfDrawable();
        sf::Transformable* sf_transform = drawable->sfTransformable();
        Transformation drawable_transform = drawable->transform();
        if (sf_transform != nullptr)
        {
            const Kinematic* kinematic = p_drawable_kinematic[drawable];
            const Transformation* actor_transform;
            if (kinematic != nullptr)
            {
                actor_transform = new Transformation(kinematic->simulate(game().fixedUpdateLag()));
            }
            else
            {
                actor_transform = &drawable->actor().transform();
            }
            drawable_transform.x += actor_transform->x;
            drawable_transform.y += actor_transform->y;
            drawable_transform.z += actor_transform->z;
            drawable_transform.rotation += actor_transform->rotation;
            drawable_transform.scale_x *= actor_transform->scale_x;
            drawable_transform.scale_y *= actor_transform->scale_y;

            sf_transform->setPosition(drawable_transform.x, drawable_transform.y);
            sf_transform->setRotation(drawable_transform.rotation);
            sf_transform->setScale(drawable_transform.scale_x, drawable_transform.scale_y);
            if (kinematic != nullptr)
            {
                delete actor_transform;
            }
        }
        draw_order.insert(
            std::pair<double, std::pair<const sf::Drawable*, const sf::Shader*>>(
                drawable_transform.z, std::pair<const sf::Drawable*, const sf::Shader*>(sf_drawable, drawable->shader())));
    }
    for (auto it = draw_order.begin(); it != draw_order.end(); ++it)
    {
        std::pair<const sf::Drawable*, const sf::Shader*>& data = it->second;
        if (data.second == nullptr)
        {
            p_window->draw(*data.first);
        }
        else
        {
            p_window->draw(*data.first, data.second);
        }
    }
    p_window->display();
}

void SFMLPlugin::gameEnd()
{
    p_window->close();
}

const std::list<sf::Event> SFMLPlugin::getEvents() const
{
    return p_event_list;
}

const InputHandler& SFMLPlugin::input() const
{
    return *p_input;
}

InputHandler& SFMLPlugin::input()
{
    return *p_input;
}

TextureManager& SFMLPlugin::textures()
{
    return *p_texture_manager;
}

const TextureManager& SFMLPlugin::textures() const
{
    return *p_texture_manager;
}

SpriteAnimationManager& SFMLPlugin::spriteAnimations()
{
    return *p_sprite_animation_manager;
}

const SpriteAnimationManager& SFMLPlugin::spriteAnimations() const
{
    return *p_sprite_animation_manager;
}

SoundBufferManager& SFMLPlugin::sounds()
{
    return *p_soundbuff_manager;
}

const SoundBufferManager& SFMLPlugin::sounds() const
{
    return *p_soundbuff_manager;
}

MusicManager& SFMLPlugin::music()
{
    return *p_music_manager;
}

const MusicManager& SFMLPlugin::music() const
{
    return *p_music_manager;
}

void SFMLPlugin::addDrawable(Drawable* drawable)
{
    p_drawable_set.insert(drawable);
    try
    {
        p_drawable_kinematic[drawable] = drawable->actor().getBehaviour<Kinematic>();
    }
    catch (exception::BehaviourNotFound e)
    {
        p_drawable_kinematic[drawable] = nullptr;
    }
}

void SFMLPlugin::removeDrawable(Drawable* drawable)
{
    p_drawable_set.erase(drawable);
    p_drawable_kinematic.erase(drawable);
}
