#include "Player.h"
#include "Engine/ConfigurationLoader.h"
#include "Animation.h"


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

MP::Player::Player(sf::Texture* texturePtr, sf::Texture* pathIconTexturePtr)
{	
	//saving path icon texture
	_a_path_icon_texture = pathIconTexturePtr;
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

void MP::Player::playerAutomaticMove(Map& aMap, TaskManager& aTaskManager)
{
	if (getPath() != nullptr and aPlayerTaskManager.getTask() == MP::TaskManager::taskType::taskNone and aTaskManager.getTask() == MP::TaskManager::taskType::taskAutoMove)
	{

		MapElement* nextDestination = getPath();//Takes new destination (new block).
		MapElement* tmp = aMap.findElementAddressSquareRange(getObiectCoord(), aMap.getMapElementList());//Return element where computer player stands.

		if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x
			and tmp->getLandTile().getObiectCoord().y + _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes down
			aPlayerTaskManager.startProcedureGoDown(*this, aMap);

		else if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x
			and tmp->getLandTile().getObiectCoord().y - _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes up
			aPlayerTaskManager.startProcedureGoUp(*this, aMap);

		else if (tmp->getLandTile().getObiectCoord().x + _block_length == nextDestination->getLandTile().getObiectCoord().x//Goes right
			and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)
			aPlayerTaskManager.startProcedureGoRight(*this, aMap);

		else if (tmp->getLandTile().getObiectCoord().x - _block_length == nextDestination->getLandTile().getObiectCoord().x//Goes left
			and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)
			aPlayerTaskManager.startProcedureGoLeft(*this, aMap);


		setPath(getPath()->getNextElement());//Deleting usless element
		delete nextDestination;
	}
	else if(getPath() == nullptr and aPlayerTaskManager.getTask() == MP::TaskManager::taskType::taskNone and aTaskManager.getTask() == MP::TaskManager::taskType::taskAutoMove)
	{
		aTaskManager.endMouseTask();
		aTaskManager.endTask();
	}
}



void MP::Player::setPath(MapElement*& newPath)
{
	_path = newPath;
}

MP::MapElement*& MP::Player::getPath()
{
	return _path;
}

void MP::Player::playerAutoAnimation(sf::Clock& globalClock)
{
	if (aPlayerTaskManager.getTask() == MP::TaskManager::taskType::taskGoUp)
		_player_animation_up(globalClock);

	if (aPlayerTaskManager.getTask() == MP::TaskManager::taskType::taskGoDown)
		_player_animation_down(globalClock);

	if (aPlayerTaskManager.getTask() == MP::TaskManager::taskType::taskGoLeft)
		_player_animation_left(globalClock);

	if (aPlayerTaskManager.getTask() == MP::TaskManager::taskType::taskGoRight)
		_player_animation_right(globalClock);
}

void MP::Player::playerAutoMove(sf::Clock& globalClock)
{
	MP::Move tmp;

	switch (aPlayerTaskManager.getTask())
	{
	case(MP::TaskManager::taskType::taskGoUp):
		tmp.moveBlockUp(*this, globalClock, aPlayerTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoLeft):
		tmp.moveBlockLeft(*this, globalClock, aPlayerTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoDown):
		tmp.moveBlockDown(*this, globalClock, aPlayerTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoRight):
		tmp.moveBlockRight(*this, globalClock, aPlayerTaskManager);
		break;
	default:
	{
		this->resetBlockLenghtCopy();
	}

	}
}

void MP::Player::deletePlayerPath()
{
	if (_path == nullptr)
		return;
	else
	{
		MapElement* tmp = _path;

		while (_path != nullptr)
		{
			_path =_path->getNextElement();
			delete tmp;
			tmp = _path;
		}
	}
}

void MP::Player::markPath()
{

	MapElement* tmp = _path;

	while (tmp != nullptr)
	{
		std::unique_ptr<PathIcon> newPathIcon = std::make_unique<PathIcon>(_a_path_icon_texture, tmp->getLandTile().getObiectCoord());
		_a_path_icon.push_back(*newPathIcon);
		tmp = tmp->getNextElement();
	}







	//MapElement* tmp = getPath();
	//while (tmp != nullptr)
	//{
	//	MapElement* tmp2 = aMap.findElementAddress(tmp->getLandTile().getObiectCoord(), aMap.getMapElementList());
	//	tmp2->getLandTile().aAnimation.setColor(sf::Color(255, 255, 0, 128));
	//	tmp = tmp->getNextElement();
	//}
}

void MP::Player::unmarkPath()
{
	_a_path_icon.clear();


	//MapElement* tmp = getPath();
	//while (tmp != nullptr)
	//{
	//	MapElement* tmp2 = aMap.findElementAddress(tmp->getLandTile().getObiectCoord(), aMap.getMapElementList());
	//	tmp2->getLandTile().aAnimation.setColor(sf::Color(255, 255, 255));
	//	tmp = tmp->getNextElement();
	//}
}

std::vector<MP::PathIcon>& MP::Player::getPathIcon()
{
	return _a_path_icon;
}
