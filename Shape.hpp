#ifndef BH_SHAPE_HPP
#define BH_SHAPE_HPP
#include "../Hum2D/Transformation.hpp"
#include "../Hum2D/Behaviour.hpp"
#include "SFMLPlugin.hpp"

namespace h2d
{
class Shape : public Behaviour
{
public:
	Transformation transform;

	Shape():Behaviour(), p_absolute(false){}

	virtual void init()
	{
		p_sfml = actor().game().getPlugin<SFMLPlugin>();
	}

	void postUpdate()
	{
		double z_index = 0.0;
		if (not p_absolute)
		{
			p_shape->setPosition(transform.x + actor().transform.x,
			                     transform.y + actor().transform.y);
			p_shape->setScale(transform.scale_x * actor().transform.scale_x,
			                  transform.scale_y * actor().transform.scale_y);
			p_shape->setRotation(transform.rotation + actor().transform.rotation);
			z_index = transform.z + actor().transform.z;
		}
		p_sfml->draw(*p_shape, z_index);
	}

	sf::Shape& shape()
	{
		return *p_shape;
	}

	const sf::Shape& shape() const
	{
		return *p_shape;
	}

	void setShape(sf::Shape& shape)
	{
		p_shape = &shape;
	}

	void transformAbsolute(bool absolute)
	{
		p_absolute = absolute;
	}

private:
	bool p_absolute;
	SFMLPlugin* p_sfml;
	sf::Shape* p_shape;
};
}
#endif
