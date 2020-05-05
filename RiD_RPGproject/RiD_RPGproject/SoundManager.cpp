#include "SoundManager.h"

void MP::SoundManager::setSound(std::string sound_name, std::string file_name)
{
	sf::SoundBuffer soundBuff;
	if (soundBuff.loadFromFile(file_name))
		this->_sound[sound_name] = soundBuff;
}

sf::SoundBuffer& MP::SoundManager::getSound(std::string sound_name)
{
	return _sound.at(sound_name);
}

//void MP::SoundManager::setMusic(std::string music_name, std::string file_name)
//{
//		this->_music[music_name] = file_name;
//}
//
//std::string& MP::SoundManager::getMusic(std::string music_name)
//{
//	return this->_music.at(music_name);
//}
