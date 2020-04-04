#include "ComputerPlayer.h"
#include "MapMove.h"


void MP::ComputerPlayer::choseDestination(Map &aMap)
{
	MP::PathCreator tmp(aMap);
	//The element where computer player stand is being took from map element list. After that, path finder will return map element list from
	//start point to destination.
	_path =  tmp.findPath(aMap.findElementAddressSquareRange(getObiectCoord(), aMap.getMapElementList())->getLandTile().getObiectCoord(),
		aMap.returnRandomWalkableElement()->getLandTile().getObiectCoord());
}

void MP::ComputerPlayer::getNextTask(Map& aMap)
{

	if (computerTasks.getTask() == MP::TaskManager::taskType::taskNone)
	{
		if (_path == nullptr)//Sets new destination.
		choseDestination(aMap);
		


		MapElement* nextDestination = _path;//Takes new destination (new block).
		MapElement* tmp = aMap.findElementAddressSquareRange(getObiectCoord(), aMap.getMapElementList());//Return element where computer player stands.

		if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x
			and tmp->getLandTile().getObiectCoord().y + _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes down
			computerTasks.startProcedureGoDown(*this, aMap);

		else if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x
			and tmp->getLandTile().getObiectCoord().y - _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes up
			computerTasks.startProcedureGoUp(*this, aMap);

		else if (tmp->getLandTile().getObiectCoord().x + _block_length == nextDestination->getLandTile().getObiectCoord().x//Goes right
			and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)
			computerTasks.startProcedureGoRight(*this, aMap);

		else if (tmp->getLandTile().getObiectCoord().x - _block_length == nextDestination->getLandTile().getObiectCoord().x//Goes left
			and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)
			computerTasks.startProcedureGoLeft(*this, aMap);
		
		_path = _path->getNextElement();//Deleting usless element
		delete nextDestination;
		
	}
}

void MP::ComputerPlayer::computerPlayerMove(sf::Clock& globalClock)
{
	MP::MapMove tmp;

	switch (computerTasks.getTask())
	{
	case(MP::TaskManager::taskType::taskGoUp):
		tmp.moveBlockUp(*this, globalClock, computerTasks);
		break;
	case(MP::TaskManager::taskType::taskGoLeft):
		tmp.moveBlockLeft(*this, globalClock, computerTasks);
		break;
	case(MP::TaskManager::taskType::taskGoDown):
		tmp.moveBlockDown(*this, globalClock, computerTasks);
		break;
	case(MP::TaskManager::taskType::taskGoRight):
		tmp.moveBlockRight(*this, globalClock, computerTasks);
		break;
	default:
	{
		this->resetBlockLenghtCopy();
	}

	}
}


MP::ComputerPlayer::ComputerPlayer(sf::Texture* texturePtr)
{

	_path = nullptr;

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

void MP::ComputerPlayer::computerPlayerAnimation(sf::Clock& globalClock)
{
	if (computerTasks.getTask() == MP::TaskManager::taskType::taskGoUp)
		computerPlayerAnimationUp(globalClock);

	if (computerTasks.getTask() == MP::TaskManager::taskType::taskGoDown)
		computerPlayerAnimationDown(globalClock);

	if (computerTasks.getTask() == MP::TaskManager::taskType::taskGoLeft)
		computerPlayerAnimationLeft(globalClock);

	if (computerTasks.getTask() == MP::TaskManager::taskType::taskGoRight)
		computerPlayerAnimationRight(globalClock);
}

void MP::ComputerPlayer::computerPlayerAnimationRight(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		animationMaker.setNextSprite(6, 8);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayer::computerPlayerAnimationLeft(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		animationMaker.setNextSprite(3, 5);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayer::computerPlayerAnimationUp(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		animationMaker.setNextSprite(9, 11);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayer::computerPlayerAnimationDown(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		animationMaker.setNextSprite(0, 2);
		setLastActiveAnimation(globalClock);
	}
}
