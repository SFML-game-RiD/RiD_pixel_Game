#include "Player.h"
#include "Engine/ConfigurationLoader.h"
#include "MapAnimation.h"

MP::Player::Player(sf::Texture* texturePtr)
{
	//Loading textures.
	//animationMaker.loadObiectTextures("img/mpimg/mpcharacter.png",3,4,64);
	animationMaker.loadObiectTextures(texturePtr,3,4,64);
	animationMaker.changeSprite(6);
	animationMaker.setScale(0.7, 0.7);
	//Getting player animation and move sleep time.
	active_obj_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("player", "SleepTime"));
	obj_animation_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("player", "animationSleepTime"));
	
	//Loading velocity.
	_velocity = RiD::ConfigurationLoader::getIntData("player", "velocity");
	//Getting player coordinates.
	setObiectCoord(RiD::ConfigurationLoader::getIntData("player", "coordinateX"), RiD::ConfigurationLoader::getIntData("player", "coordinateY"));
	

	

}


void MP::Player::playerAnimation(sf::Clock& globalClock, MP::TaskManager& aTaskManager)
{
	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoUp)
		playerAnimationUp(globalClock);

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoDown)
		playerAnimationDown(globalClock);

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoLeft)
		playerAnimationLeft(globalClock);

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoRight)
		playerAnimationRight(globalClock);
}

void MP::Player::playerAnimationRight(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		animationMaker.setNextSprite(6, 8);
		setLastActiveAnimation(globalClock);
	}
}

void MP::Player::playerAnimationLeft(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		animationMaker.setNextSprite(3, 5);
		setLastActiveAnimation(globalClock);
	}
}

void MP::Player::playerAnimationUp(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		animationMaker.setNextSprite(9, 11);
		setLastActiveAnimation(globalClock);
	}
}

void MP::Player::playerAnimationDown(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		animationMaker.setNextSprite(0, 2);
		setLastActiveAnimation(globalClock);
	}
}
