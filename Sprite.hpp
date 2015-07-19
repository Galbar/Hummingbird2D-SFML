#ifndef BH_SPRITE_HPP
#define BH_SPRITE_HPP
#include <string>
#include "../Hum2D/Transformation.hpp"
#include "../Hum2D/Behaviour.hpp"
#include "SFMLPlugin.hpp"

namespace h2d
{
class Sprite : public Behaviour
{
public:
	Transformation transform;

	Sprite():Behaviour(), p_absolute(false){}

	void init()
	{
		p_sfml = actor().game().getPlugin<SFMLPlugin>();
	}

	void postUpdate()
	{
		double z_index = 0.0;
		if (not p_absolute)
		{
			p_sprite.setPosition(transform.x + actor().transform.x,
		                         transform.y + actor().transform.y);
			p_sprite.setScale(transform.scale_x * actor().transform.scale_x,
		                      transform.scale_y * actor().transform.scale_y);
			p_sprite.setRotation(transform.rotation + actor().transform.rotation);
			z_index = transform.z + actor().transform.z;
		}
		p_sfml->draw(p_sprite, z_index);
	}

	sf::Sprite& sprite()
	{
		return p_sprite;
	}

	const sf::Sprite& sprite() const
	{
		return p_sprite;
	}

	void transformAbsolute(bool absolute)
	{
		p_absolute = absolute;
	}

private:
	bool p_absolute;
	SFMLPlugin* p_sfml;
	sf::Sprite p_sprite;
};
}
#endif
