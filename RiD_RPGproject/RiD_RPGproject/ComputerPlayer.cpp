#include "ComputerPlayer.h"
#include "Move.h"


void MP::ComputerPlayer::choseDestination(Map &aMap)
{
	MP::PathCreator tmp(aMap);
	sf::Vector2f destinationCoord = aMap.returnRandomWalkableElement()->getLandTile().getObiectCoord();
	MapElement* startingElement = aMap.findElementAddressSquareRange(getObiectCoord(), aMap.getMapElementList());

	while(destinationCoord == startingElement->getLandTile().getObiectCoord())
		destinationCoord = aMap.returnRandomWalkableElement()->getLandTile().getObiectCoord();

	//Chose random destination and calculate path.
	
	_path =  tmp.findPath(startingElement->getLandTile().getObiectCoord(),destinationCoord);
}

void MP::ComputerPlayer::getNextTask(Map& aMap)
{

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskNone)
	{
		if (_path == nullptr)//Sets new destination.
		choseDestination(aMap);
		


		MapElement* nextDestination = _path;//Takes new destination (new block).
		MapElement* tmp = aMap.findElementAddressSquareRange(getObiectCoord(), aMap.getMapElementList());//Return element where computer player stands.

		if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x
			and tmp->getLandTile().getObiectCoord().y + _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes down
			aTaskManager.startProcedureGoDown(*this, aMap);

		else if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x
			and tmp->getLandTile().getObiectCoord().y - _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes up
			aTaskManager.startProcedureGoUp(*this, aMap);

		else if (tmp->getLandTile().getObiectCoord().x + _block_length == nextDestination->getLandTile().getObiectCoord().x//Goes right
			and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)
			aTaskManager.startProcedureGoRight(*this, aMap);

		else if (tmp->getLandTile().getObiectCoord().x - _block_length == nextDestination->getLandTile().getObiectCoord().x//Goes left
			and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)
			aTaskManager.startProcedureGoLeft(*this, aMap);
		

		_path = _path->getNextElement();//Deleting usless element
		delete nextDestination;
		
	}
}

void MP::ComputerPlayer::computerPlayerMove(sf::Clock& globalClock)
{
	MP::Move tmp;

	switch (aTaskManager.getTask())
	{
	case(MP::TaskManager::taskType::taskGoUp):
		tmp.moveBlockUp(*this, globalClock, aTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoLeft):
		tmp.moveBlockLeft(*this, globalClock, aTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoDown):
		tmp.moveBlockDown(*this, globalClock, aTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoRight):
		tmp.moveBlockRight(*this, globalClock, aTaskManager);
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
	aAnimation.loadObiectTextures(texturePtr, 3, 4, 64);
	aAnimation.changeSprite(6);
	aAnimation.setScale(0.7, 0.7);

	//Getting computer player animation and move sleep time.
	active_obj_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("computer player", "SleepTime"));
	_obj_animation_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("computer player", "animationSleepTime"));

	//Loading velocity.
	_velocity = RiD::ConfigurationLoader::getIntData("computer player", "velocity");

	//Getting player coordinates.
	setObiectCoord(RiD::ConfigurationLoader::getIntData("computer player", "coordinateX"), RiD::ConfigurationLoader::getIntData("computer player", "coordinateY"));
}

void MP::ComputerPlayer::computerPlayerAnimation(sf::Clock& globalClock)
{
	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoUp)
		_computer_player_animation_up(globalClock);

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoDown)
		_computer_player_animation_down(globalClock);

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoLeft)
		_computer_player_animation_left(globalClock);

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskGoRight)
		_computer_player_animation_right(globalClock);
}

void MP::ComputerPlayer::_computer_player_animation_right(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(6, 8);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayer::_computer_player_animation_left(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(3, 5);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayer::_computer_player_animation_up(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(9, 11);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayer::_computer_player_animation_down(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(0, 2);
		setLastActiveAnimation(globalClock);
	}
}
