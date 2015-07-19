#ifndef BH_ANIMATED_SPRITE_HPP
#define BH_ANIMATED_SPRITE_HPP
#include <vector>
#include "Sprite.hpp"
#include "../Hum2D/Time.hpp"

namespace h2d
{
struct Frame
{
	unsigned int tile_id;
	unsigned int milliseconds;
};

class AnimatedSprite : public Sprite
{
public:
	Transformation transform;

	AnimatedSprite():
	Sprite(),
	p_playing(true),
	p_h_margin(0),
	p_v_margin(0),
	p_tile_width(0),
	p_tile_height(0),
	p_current_frame(0),
	_nx(0)
	{}

	void postUpdate()
	{
		if (p_playing)
		{
			p_frame_time -= actor().game().deltaTime();
			if (p_frame_time.asMilliseconds() <= 0)
			{
				updateFrame((p_current_frame +1) % p_tile_order.size());
			}
		}
		Sprite::postUpdate();
	}

	void setMargin(int h_margin, int v_margin)
	{
		p_h_margin = h_margin;
		p_v_margin = v_margin;
		updateFrame(0);
	}

	void setFrameSize(int width, int height)
	{
		p_tile_width = width;
		p_tile_height = height;
		updateFrame(0);
	}

    void setFrameOrder(const std::vector<Frame>& frame_order)
	{
		p_tile_order = frame_order;
		updateFrame(0);
	}

	void setPlaying(bool playing)
	{
		p_playing = playing;
	}

private:
	struct TexCoords
	{
		unsigned int x, y;
	};

	void updateFrame(int frame)
	{
		if (p_tile_order.size() == 0 or sprite().getTexture() == nullptr)
			return;
		p_current_frame = frame;
		int mil = p_tile_order[p_current_frame].milliseconds;
		p_frame_time = Time::milliseconds(mil);
		auto tex_coords = getTexCoords();
		sprite().setTextureRect(sf::IntRect(tex_coords.x, tex_coords.y, p_tile_width, p_tile_height));
	}

	TexCoords getTexCoords()
	{
		_nx = sprite().getTexture()->getSize().x / (p_tile_width + p_h_margin);
		return TexCoords{
			(p_tile_order[p_current_frame].tile_id % _nx) * (p_tile_width + p_h_margin) + p_h_margin,
			(p_tile_order[p_current_frame].tile_id / _nx) * (p_tile_height + p_v_margin) + p_v_margin};
	}

	bool p_playing;
	int p_h_margin;
	int p_v_margin;
	int p_tile_width;
	int p_tile_height;
	int p_current_frame;
	int _nx;
	std::vector<Frame> p_tile_order;
	Time p_frame_time;
};
}
#endif
