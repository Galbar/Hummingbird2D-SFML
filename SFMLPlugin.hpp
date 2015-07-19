#ifndef SFML_PLUGIN_HPP
#define SFML_PLUGIN_HPP
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "../Hum2D/Plugin.hpp"
#include "TextureManager.hpp"
#include "SoundBufferManager.hpp"
#include "MusicManager.hpp"
#include "InputHandler.hpp"

namespace h2d
{
class SFMLPlugin : public Plugin
{
public:
	SFMLPlugin(int window_width, int window_height, std::string window_title):
	p_window_width(window_width),
	p_window_height(window_height),
	p_window_title(window_title)
	{}
	~SFMLPlugin()
	{}

	sf::RenderWindow& window()
	{
		return *p_window;
	}

	const sf::RenderWindow& window() const
	{
		return *p_window;
	}

	void gameStart()
	{
		p_window = new sf::RenderWindow(sf::VideoMode(p_window_width, p_window_height), p_window_title);
	}
	void preUpdate()
	{
		p_input.update();
		sf::Event event;
		while (p_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				p_window->close();
				game().setRunning(false);
			}
			p_input.handleEvent(event);
			p_event_list.push_back(event);
		}
	}
	void postUpdate()
	{
		p_event_list.clear();
		p_window->clear();
		while (not p_drawable_list.empty())
		{
			sf::Drawable& d = p_drawable_list.begin()->second;
			p_window->draw(d);
			p_drawable_list.erase(p_drawable_list.begin());
		}
		p_window->display();
		p_drawable_list.clear();
	}
	void gameEnd()
	{
		p_window->close();
	}

	const std::list<sf::Event> getEvents() const
	{
		return p_event_list;
	}

	void draw(sf::Drawable& drawable, double z_index = 0.0)
	{
		p_drawable_list.insert(std::pair<double, sf::Drawable&>(z_index, drawable));
	}

	InputHandler& input()
	{
		return p_input;
	}

	TextureManager& textures()
	{
		return p_texture_manager;
	}

	const TextureManager& textures() const
	{
		return p_texture_manager;
	}

	SoundBufferManager& sounds()
	{
		return p_soundbuff_manager;
	}

	const SoundBufferManager& sounds() const
	{
		return p_soundbuff_manager;
	}

	MusicManager& music()
	{
		return p_music_manager;
	}

	const MusicManager& music() const
	{
		return p_music_manager;
	}

private:
	int p_window_width;
	int p_window_height;
	std::string p_window_title;
	sf::RenderWindow* p_window;
	std::list<sf::Event> p_event_list;
	std::multimap<double, sf::Drawable&> p_drawable_list;
	InputHandler p_input;
	TextureManager p_texture_manager;
	MusicManager p_music_manager;
	SoundBufferManager p_soundbuff_manager;
};
}
#endif
