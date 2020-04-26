#include "Player.h"
#include "Engine/ConfigurationLoader.h"
#include "Animation.h"
#include "Move.h"
#include "pathCreator.h"

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


void MP::Player::_player_animation(sf::Clock& globalClock, TaskManager &aMainTaskManager)
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

void MP::Player::_player_move(sf::Clock& aGameClock, TaskManager& aMainTaskManager)
{
	Move tmp;

	switch (aMainTaskManager.getTask(MP::TaskManager::taskRange::order))
	{
	case(MP::TaskManager::taskType::taskGoUp):
		tmp.moveBlockUp(*this, aGameClock, aMainTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoLeft):
		tmp.moveBlockLeft(*this, aGameClock, aMainTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoDown):
		tmp.moveBlockDown(*this, aGameClock, aMainTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoRight):
		tmp.moveBlockRight(*this, aGameClock, aMainTaskManager);
		break;
	default:
	{
		this->resetBlockLenghtCopy();
	}

	}
}


void MP::Player::_player_automatic_move(Map& aMap, TaskManager& aTaskManager)
{
	if (_path != nullptr and  aPawnObiectTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskNone)
	{

		MapElement* nextDestination = _path;//Takes new destination (new block).
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


		_set_path(_path->getNextElement());//Deleting usless element
		delete nextDestination;
	}
	else if(_path == nullptr and aPawnObiectTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskNone)
	{
		aTaskManager.resetOrdersAndReply();
	}
}



void MP::Player::_set_path(MapElement*& newPath)
{
	_path = newPath;
}


void MP::Player::_player_auto_animation(sf::Clock& globalClock)
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

void MP::Player::_player_auto_move(sf::Clock& globalClock)
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

void MP::Player::_delete_player_path()
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

void MP::Player::_mark_path()
{

	MapElement* tmp = _path;

	while (tmp != nullptr)
	{
		std::unique_ptr<PathIcon> newPathIcon = std::make_unique<PathIcon>(_a_path_icon_texture, tmp->getLandTile().getObiectCoord());
		_a_path_icon.push_back(*newPathIcon);
		tmp = tmp->getNextElement();
	}

}

void MP::Player::_unmark_path()
{
	_a_path_icon.clear();
}

void MP::Player::goToPlace(Map& aGameMap, TaskManager& aMainTaskManger)
{
	MapElement *currentBlock = aGameMap.findElementAddressSquareRange(this->getObiectCoord(), aGameMap.getMapElementList());


	if (currentBlock->getPlace() != nullptr)
	{
		aMainTaskManger.setState(TaskManager::stateType::statePlacesMenu);
	}
}

void MP::Player::update(TaskManager& aMainTaskManager, sf::Clock& GameClock, MP::Map& aMap, sf::Vector2f mouseGameCoord)
{
	_procedure_player_auto_or_normal_move(aMainTaskManager, GameClock, aMap, mouseGameCoord);
}

void MP::Player::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
	std::vector<PathIcon> tmpPathCopy = _a_path_icon;
	for (int i = 0; i < tmpPathCopy.size(); i++)
	{
		mainWindow.draw(tmpPathCopy[i].aAnimation.getObiectSprite());
	}
}

void MP::Player::_procedure_player_auto_or_normal_move(TaskManager& aMainTaskManager, sf::Clock& gameClock, MP::Map &aMap, sf::Vector2f& mouseGameCoord)
{
	switch (aMainTaskManager.getTask(MP::TaskManager::taskRange::mainOrder))
	{
	case(MP::TaskManager::taskType::taskNormalMove):
	{
		_player_move(gameClock, aMainTaskManager);

		_player_animation(gameClock, aMainTaskManager);

	}break;
	case(MP::TaskManager::taskType::taskAutoMove):
	{



		switch (aMainTaskManager.getTask(MP::TaskManager::taskRange::order))
		{
		case(MP::TaskManager::taskType::taskCreateAutoPath):
		{
			//geting start and stop coordinates

			MapElement* start = aMap.findElementAddressSquareRange(getObiectCoord(), aMap.getMapElementList());

			MapElement* stop = aMap.findElementAddressSquareRange(mouseGameCoord, aMap.getMapElementList());

			if (stop->isWalkable())
			{
				if (start->getLandTile().getObiectCoord() != stop->getLandTile().getObiectCoord())
				{

					checkingVector = stop->getLandTile().getObiectCoord();

					//creating path
					MP::PathCreator  tmp(aMap);

					aMainTaskManager.setTask(MP::TaskManager::taskRange::reply, MP::TaskManager::taskType::taskWaitForDoubleClickLeft); //computer waiting for player reply
					_set_path(tmp.findPath(start->getLandTile().getObiectCoord(), stop->getLandTile().getObiectCoord()));

					_mark_path();
				}

			}


			aMainTaskManager.endTask(MP::TaskManager::taskRange::order);
			aMainTaskManager.endTask(MP::TaskManager::taskRange::mainOrder);


		}break;
		case(MP::TaskManager::taskType::taskBreakAutoMove)://breaks auto move
		{
			if (aPawnObiectTaskManager.getTask(TaskManager::taskRange::order) != TaskManager::taskType::taskNone)
			{
				_player_auto_animation(gameClock);
				_player_auto_move(gameClock);
			}
			else
			{
				_delete_player_path();
				aMainTaskManager.resetOrdersAndReply();
			}
		}break;
		case(MP::TaskManager::taskType::taskExecuteAutoMove)://execute auto move		
		{
			_player_automatic_move(aMap, aMainTaskManager);
			_player_auto_animation(gameClock);
			_player_auto_move(gameClock);

		}break;
		case(MP::TaskManager::taskType::taskDoubleClickLeft)://starts procedure auto move if player clicked second time
		{

			MapElement* checkingElement = aMap.findElementAddressSquareRange(mouseGameCoord, aMap.getMapElementList());

			if (checkingElement->getLandTile().getObiectCoord().x == checkingVector.x and checkingElement->getLandTile().getObiectCoord().y == checkingVector.y)
			{
				_unmark_path();
				aMainTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskExecuteAutoMove);
			}
			else
			{
				aMainTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskBreakAutoMove);
				_unmark_path();
			}
		}break;
		}
	}break;

	}
}
