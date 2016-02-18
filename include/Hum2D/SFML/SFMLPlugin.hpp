#ifndef SFML_PLUGIN_HPP
#define SFML_PLUGIN_HPP
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Hum2D/Plugin.hpp"
#include "TextureManager.hpp"
#include "SpriteAnimation.hpp"
#include "SoundManager.hpp"
#include "MusicManager.hpp"
#include "InputHandler.hpp"

namespace h2d
{
class Drawable;
class Kinematic;
class SFMLPlugin : public Plugin
{
public:
    SFMLPlugin(int window_width, int window_height, std::string window_title);
    ~SFMLPlugin();
    void gameStart();
    void preFixedUpdate();
    void postFixedUpdate();
    void postUpdate();
    void gameEnd();
    const std::vector<sf::Event> getEvents() const;
    void draw(sf::Drawable* drawable, double z_index = 0.0);
    sf::RenderWindow& window();
    const sf::RenderWindow& window() const;
    InputHandler& input();
    const InputHandler& input() const;
    SpriteAnimationManager& spriteAnimations();
    const SpriteAnimationManager& spriteAnimations() const;
    TextureManager& textures();
    const TextureManager& textures() const;
    SoundManager& sounds();
    const SoundManager& sounds() const;
    MusicManager& music();
    const MusicManager& music() const;

    void addDrawable(Drawable* drawable);
    void removeDrawable(Drawable* drawable);

private:
    int p_window_width;
    int p_window_height;
    std::string p_window_title;
    sf::RenderWindow* p_window;
    std::vector<sf::Event> p_event_list;
    std::unordered_set<Drawable*> p_drawable_set;
    std::unordered_map<Drawable*, const Kinematic*> p_drawable_kinematic;
    InputHandler p_input;
    TextureManager p_texture_manager;
    SpriteAnimationManager p_sprite_animation_manager;
    MusicManager p_music_manager;
    SoundManager p_sound_manager;
};
}
#endif
