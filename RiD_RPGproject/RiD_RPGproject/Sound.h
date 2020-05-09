#pragma once
#include <SFML/Audio.hpp>
namespace MP
{ 
class Sound
{
private:
	sf::Sound _sound;

	float _volume;
public:
	
	Sound();

	void playSound(sf::SoundBuffer & aSoundBuffer);

	bool isPlaying();

	void setSpeed(float speed);
};
}
