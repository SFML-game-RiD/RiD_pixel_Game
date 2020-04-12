#include "Player.h"
#include "Engine/ConfigurationLoader.h"
#include "Animation.h"
#include "Move.h"

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


void MP::Player::playerAnimation(sf::Clock& globalClock, TaskManager &aMainTaskManager)
{
	if (aMainTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskGoUp)
		_player_animation_up(globalClock);

	if (aMainTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskGoDown)
		_player_animation_down(globalClock);

	if (aMainTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskGoLeft)
		_player_animation_left(globalClock);

	if (aMainTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskGoRight)
		_player_animation_right(globalClock);
}

void MP::Player::playerAutomaticMove(Map& aMap, TaskManager& aTaskManager)
{
	if (getPath() != nullptr and  aPawnObiectTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskNone)
	{

		MapElement* nextDestination = getPath();//Takes new destination (new block).
		MapElement* tmp = aMap.findElementAddressSquareRange(getObiectCoord(), aMap.getMapElementList());//Return element where computer player stands.

		if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x
			and tmp->getLandTile().getObiectCoord().y + _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes down

			aPawnObiectTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskGoDown);

		else if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x
			and tmp->getLandTile().getObiectCoord().y - _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes up

			aPawnObiectTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskGoUp);

		else if (tmp->getLandTile().getObiectCoord().x + _block_length == nextDestination->getLandTile().getObiectCoord().x//Goes right
			and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)

			aPawnObiectTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskGoRight);

		else if (tmp->getLandTile().getObiectCoord().x - _block_length == nextDestination->getLandTile().getObiectCoord().x//Goes left
			and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)

			aPawnObiectTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskGoLeft);


		setPath(getPath()->getNextElement());//Deleting usless element
		delete nextDestination;
	}
	else if(getPath() == nullptr and aPawnObiectTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskNone)
	{
		aTaskManager.resetOrdersAndReply();
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
	if (aPawnObiectTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskGoUp)
		_player_animation_up(globalClock);

	if (aPawnObiectTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskGoDown)
		_player_animation_down(globalClock);

	if (aPawnObiectTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskGoLeft)
		_player_animation_left(globalClock);

	if (aPawnObiectTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskGoRight)
		_player_animation_right(globalClock);
}

void MP::Player::playerAutoMove(sf::Clock& globalClock)
{
	MP::Move tmp;

	switch (aPawnObiectTaskManager.getTask(MP::TaskManager::taskRange::order))
	{
	case(MP::TaskManager::taskType::taskGoUp):
		tmp.moveBlockUp(*this, globalClock);
		break;
	case(MP::TaskManager::taskType::taskGoLeft):
		tmp.moveBlockLeft(*this, globalClock);
		break;
	case(MP::TaskManager::taskType::taskGoDown):
		tmp.moveBlockDown(*this, globalClock);
		break;
	case(MP::TaskManager::taskType::taskGoRight):
		tmp.moveBlockRight(*this, globalClock);
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

}

void MP::Player::unmarkPath()
{
	_a_path_icon.clear();
}

std::vector<MP::PathIcon>& MP::Player::getPathIcon()
{
	return _a_path_icon;
}
