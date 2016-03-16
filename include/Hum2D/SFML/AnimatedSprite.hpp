#ifndef H2D_ANIMATED_SPRITE_HPP
#define H2D_ANIMATED_SPRITE_HPP
#include "Hum2D/Hum2D.hpp"
#include "Drawable.hpp"

namespace h2d
{
class Time;
struct SpriteAnimation;
class AnimatedSprite : public Drawable
{
public:
    enum Status { PLAYING, PAUSED, STOPPED };
    AnimatedSprite(const SpriteAnimation* animation);
    virtual ~AnimatedSprite();
    const SpriteAnimation* spriteAnimation() const;
    void setSpriteAnimation(const SpriteAnimation* animation);
    sf::Drawable* sfDrawable() override;
    sf::Transformable* sfTransformable() override;
    sf::Sprite& sprite();
    const sf::Sprite& sprite() const;

    void play();
    void pause();
    void stop();
    Status status() const;
    unsigned int frameIndex() const;
    void frameIndex(unsigned int frame_index);

    void setLooping(bool looping);
    bool isLooping() const;

    static const char* behaviorName();

private:
    Status p_status;
    bool p_loop;
    unsigned int p_frame_index;
    const SpriteAnimation* p_animation;
    Time p_time;
    sf::Sprite p_sprite;
};
}
#endif
