#include "Sound.h"
#include "Engine/ConfigurationLoader.h"

MP::Sound::Sound()
{
	_sound.setVolume(float(RiD::ConfigurationLoader::getIntData("game settings", "soundVolume")));
}

void MP::Sound::playSound(sf::SoundBuffer& aSoundBuffer)
{
	_sound.setBuffer(aSoundBuffer);
	_sound.play();
}

bool MP::Sound::isPlaying()
{
	if (sf::SoundSource::Status::Paused == _sound.getStatus() or sf::SoundSource::Status::Stopped == _sound.getStatus())
		return false;
	else
		return true;
}

void MP::Sound::setSpeed(float speed)
{
	_sound.setPitch(speed);
}
