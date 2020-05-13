#pragma once

#include <map>
#include <exception>
#include "SFML/Audio.hpp"

namespace RiD
{
	class AudioManager
	{
	private:
		std::map<std::string, sf::SoundBuffer> _audio_buffer;
		std::map<std::string, sf::Sound> _sounds;

		sf::Sound _sound;
		sf::Music _music;

	public:
		AudioManager();

		void setSoundBuffer(std::string sound_name, std::string file_name);

		sf::SoundBuffer& getSoundBuffer(std::string sound_name);

		void playSound(const std::string &sound_name, const float& volume, const float& pitch = 1.f, const bool& loop = false);

		void playMusic(const std::string& file_name, const float& volume);
	};
}