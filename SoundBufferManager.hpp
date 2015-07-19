#ifndef H2B_SOUNDBUFFER_MANAGER_HPP
#define H2B_SOUNDBUFFER_MANAGER_HPP
#include <SFML/Audio.hpp>
#include "../Hum2D/ResourceManager.hpp"

namespace h2d
{
class SoundBufferManager : public ResourceManager<sf::SoundBuffer>
{
protected:
	sf::SoundBuffer* loadResource(const std::string& name) override
	{
		sf::SoundBuffer* resource = new sf::SoundBuffer();
		if (not resource->loadFromFile(name))
			return nullptr;
		return resource;
	}
};
}
#endif
