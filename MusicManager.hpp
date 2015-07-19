#ifndef H2B_MUSIC_MANAGER_HPP
#define H2B_MUSIC_MANAGER_HPP
#include <SFML/Audio.hpp>
#include "../Hum2D/ResourceManager.hpp"

namespace h2d
{
class MusicManager : public ResourceManager<sf::Music>
{
protected:
	sf::Music* loadResource(const std::string& name) override
	{
		sf::Music* resource = new sf::Music();
		if (not resource->openFromFile(name))
			return nullptr;
		return resource;
	}
};
}
#endif
