#include "SoundManager.h"

MP::SoundManager::SoundManager()
{
	setSound("pawnSound", "sound/horse_sound.wav");
	setSound("activeButtonSound", "sound/active_button_sound.wav");
	setSound("pressedButtonSound", "sound/pressed_button_sound.wav");
}

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
