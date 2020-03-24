#include "PawnObiect.h"


MP::PawnObiect::PawnObiect()
{
	_ready_animation_time = sf::milliseconds(0);
	_last_animation_active = sf::milliseconds(0);
}



void MP::PawnObiect::pawnAnimation(sf::Clock & globalClock,MP::TaskManager &aTaskManager)
{
	if(aTaskManager.getTask()==MP::TaskManager::taskType::taskGoUp)
	pawnAnimationUp(globalClock);

	if(aTaskManager.getTask() == MP::TaskManager::taskType::taskGoDown)
		pawnAnimationDown(globalClock);

	if(aTaskManager.getTask() == MP::TaskManager::taskType::taskGoLeft)
		pawnAnimationLeft(globalClock);

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoRight)
		pawnAnimationRight(globalClock);
}

void MP::PawnObiect::pawnAnimationRight(sf::Clock & globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		setNextSprite(6, 8);
		setLastActiveAnimation(globalClock);
	}
}

void MP::PawnObiect::pawnAnimationLeft(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		setNextSprite(3, 5);
		setLastActiveAnimation(globalClock);
	}
}

void MP::PawnObiect::pawnAnimationUp(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		setNextSprite(9, 11);
		setLastActiveAnimation(globalClock);
	}
}

void MP::PawnObiect::pawnAnimationDown(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		setNextSprite(0, 2);
		setLastActiveAnimation(globalClock);
	}
}

void MP::PawnObiect::setNextSprite(int from, int to)
{
	int currentSpriteNumber = animationMaker.getCurrentSprite();

	if (currentSpriteNumber < to)
		currentSpriteNumber++;
	else if (currentSpriteNumber == to)
		currentSpriteNumber = from;

	animationMaker.changeSprite(currentSpriteNumber);
}
