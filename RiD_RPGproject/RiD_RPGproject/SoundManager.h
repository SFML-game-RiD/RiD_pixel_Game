#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <map>

namespace MP
{
	class SoundManager
	{
	private:

		std::map<std::string, sf::SoundBuffer> _sound;

		std::map<std::string, sf::Music> _music;

	public:
			
		
		//Sets sound.
		//@param sound_name name of the sound.
		//@param file_name name of the file from which it will be taken.
		void setSound(std::string sound_name, std::string file_name);
		
		//Returns sound.
		//@param sound_name name of the sound.
		//@returns sound.
		sf::SoundBuffer& getSound(std::string sound_name);

		//Sets music.
		//@param music_name name of the music.
		//@param file_name name of the file from which it will be taken.
		void setMusic(std::string music_name, std::string file_name);

		//Returns music.
		//@param music_name name of the music.
		//@return music
		sf::Music& getMusic(std::string music_name);
	};

}