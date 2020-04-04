#include "ComputerPlayer.h"



MP::ComputerPlayer::ComputerPlayer(sf::Texture* texturePtr)
{

	//Loading textures.
	animationMaker.loadObiectTextures(texturePtr, 3, 4, 64);
	animationMaker.changeSprite(6);
	animationMaker.setScale(0.7, 0.7);

	//Getting computer player animation and move sleep time.
	active_obj_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("player", "SleepTime"));
	obj_animation_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("player", "animationSleepTime"));

	//Loading velocity.
	_velocity = RiD::ConfigurationLoader::getIntData("player", "velocity");

	//Getting player coordinates.
	setObiectCoord(RiD::ConfigurationLoader::getIntData("player", "coordinateX"), RiD::ConfigurationLoader::getIntData("player", "coordinateY"));
}

void MP::ComputerPlayer::computerPlayerAnimation(sf::Clock& globalClock, MP::TaskManager& aTaskManager)
{
}

void MP::ComputerPlayer::computerPlayerAnimationRight(sf::Clock& globalClock)
{
}

void MP::ComputerPlayer::computerPlayerAnimationLeft(sf::Clock& globalClock)
{
}

void MP::ComputerPlayer::computerPlayerAnimationUp(sf::Clock& globalClock)
{
}

void MP::ComputerPlayer::computerPlayerAnimationDown(sf::Clock& globalClock)
{
}
