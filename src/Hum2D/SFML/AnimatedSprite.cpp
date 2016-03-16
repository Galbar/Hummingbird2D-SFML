#include "SpriteAnimation.hpp"
#include "AnimatedSprite.hpp"
using namespace h2d;

AnimatedSprite::AnimatedSprite(const SpriteAnimation* animation):
p_loop(true)
{
    setSpriteAnimation(animation);
    p_status = PLAYING;
}

AnimatedSprite::~AnimatedSprite()
{}

void AnimatedSprite::setSpriteAnimation(const SpriteAnimation* animation)
{
    p_animation = animation;
    p_sprite.setTexture(*animation->texture);
    p_time = Time::nanoseconds(0);
    p_frame_index = 0;
    int top, left, idx, sheet_width;
    sheet_width = p_animation->texture->getSize().x - p_animation->offset_x;
    idx = p_animation->frame_order[p_frame_index];
    left = idx * (p_animation->margin_x + p_animation->width);
    top = p_animation->offset_y + (p_animation->margin_y + p_animation->height) * (left / sheet_width);
    left = (left % sheet_width) + p_animation->offset_x;

    p_sprite.setTextureRect(sf::IntRect(left, top, p_animation->width, p_animation->height));
}

const SpriteAnimation* AnimatedSprite::spriteAnimation() const
{
    return p_animation;
}

sf::Drawable* AnimatedSprite::sfDrawable()
{
    if (p_status == PLAYING)
    {
        p_time += actor().game().deltaTime();
        while (p_time > p_animation->frame_time[p_frame_index])
        {
            p_time -= p_animation->frame_time[p_frame_index];
            ++p_frame_index;
            if (p_frame_index == p_animation->frame_time.size())
            {
                if (p_loop)
                {
                    p_frame_index %= p_animation->frame_time.size();
                }
                else
                {
                    --p_frame_index;
                    p_status = STOPPED;
                }
            }
        }
        int top, left, idx, sheet_width;
        sheet_width = p_animation->texture->getSize().x - p_animation->offset_x;
        idx = p_animation->frame_order[p_frame_index];
        left = idx * (p_animation->margin_x + p_animation->width);
        top = p_animation->offset_y + (p_animation->margin_y + p_animation->height) * (left / sheet_width);
        left = (left % sheet_width) + p_animation->offset_x;

        p_sprite.setTextureRect(sf::IntRect(left, top, p_animation->width, p_animation->height));
    }
    return &p_sprite;
}

sf::Transformable* AnimatedSprite::sfTransformable()
{
    return &p_sprite;
}

sf::Sprite& AnimatedSprite::sprite()
{
    return p_sprite;
}

const sf::Sprite& AnimatedSprite::sprite() const
{
    return p_sprite;
}

void AnimatedSprite::play()
{
    p_status = PLAYING;
}

void AnimatedSprite::pause()
{
    p_status = PAUSED;
}

void AnimatedSprite::stop()
{
    p_status = STOPPED;
    p_frame_index = 0;
}

AnimatedSprite::Status AnimatedSprite::status() const
{
    return p_status;
}

unsigned int AnimatedSprite::frameIndex() const
{
    return p_frame_index;
}

void AnimatedSprite::frameIndex(unsigned int frame_index)
{
    p_frame_index = frame_index % p_animation->frame_time.size();
    p_time -= p_time;
}

void AnimatedSprite::setLooping(bool looping)
{
    p_loop = looping;
}

bool AnimatedSprite::isLooping() const
{
    return p_loop;
}

const char* AnimatedSprite::behaviorName()
{
    return "h2d::AnimatedSprite";
}
