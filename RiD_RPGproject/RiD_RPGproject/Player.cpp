#include "Player.h"
#include "Engine/ConfigurationLoader.h"
#include "Animation.h"

MP::Player::Player(sf::Texture* texturePtr)
{
	//Loading textures.
	aAnimation.loadObiectTextures(texturePtr,3,4,64);
	aAnimation.changeSprite(6);
	aAnimation.setScale(0.7, 0.7);
	//Getting player animation and move sleep time.
	active_obj_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("player", "SleepTime"));
	_obj_animation_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("player", "animationSleepTime"));
	
	//Loading velocity.
	_velocity = RiD::ConfigurationLoader::getIntData("player", "velocity");
	//Getting player coordinates.
	setObiectCoord(RiD::ConfigurationLoader::getIntData("player", "coordinateX"), RiD::ConfigurationLoader::getIntData("player", "coordinateY"));

}


void MP::Player::playerAnimation(sf::Clock& globalClock, MP::TaskManager& aTaskManager)
{
	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoUp)
		_player_animation_up(globalClock);

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoDown)
		_player_animation_down(globalClock);

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoLeft)
		_player_animation_left(globalClock);

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoRight)
		_player_animation_right(globalClock);
}

void MP::Player::_player_animation_right(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(6, 8);
		setLastActiveAnimation(globalClock);
	}
}

void MP::Player::_player_animation_left(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(3, 5);
		setLastActiveAnimation(globalClock);
	}
}

void MP::Player::_player_animation_up(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(9, 11);
		setLastActiveAnimation(globalClock);
	}
}

void MP::Player::_player_animation_down(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(0, 2);
		setLastActiveAnimation(globalClock);
	}
}
