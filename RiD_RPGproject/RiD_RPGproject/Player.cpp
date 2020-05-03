#include "Player.h"
#include "Engine/ConfigurationLoader.h"
#include "SpriteAnimation.h"
#include "Move.h"
#include "PathCreator.h"

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

void MP::Player::_player_animation_idle(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time+ sf::milliseconds(1000))
	{
		aAnimation.setNextSprite(12, 14);
		setLastActiveAnimation(globalClock);
	}
}

MP::Player::Player(sf::Texture* texturePtr, sf::Texture* pathIconTexturePtr)
{	
	_path = nullptr;
	//saving path icon texture
	_a_path_icon_texture = pathIconTexturePtr;
	//Loading textures.
	aAnimation.loadObiectTextures(texturePtr,3,5,64);
	aAnimation.changeSprite(6);
	aAnimation.setScale(float(0.7), float(0.7));
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
	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskGoUp,false))
		_player_animation_up(globalClock);

	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskGoDown, false))
		_player_animation_down(globalClock);

	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskGoLeft, false))
		_player_animation_left(globalClock);

	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskGoRight, false))
		_player_animation_right(globalClock);

	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskNone, false))
		_player_animation_idle(globalClock);
}

void MP::Player::_player_move(sf::Clock& aGameClock, TaskManager& aMainTaskManager)
{
	Move tmp;

	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskGoUp, false))
		tmp.moveBlockUp(*this, aGameClock, aMainTaskManager);

	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskGoLeft, false))
		tmp.moveBlockLeft(*this, aGameClock, aMainTaskManager);

	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskGoDown, false))
		tmp.moveBlockDown(*this, aGameClock, aMainTaskManager);

	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskGoRight, false))
		tmp.moveBlockRight(*this, aGameClock, aMainTaskManager);

	if (aMainTaskManager.isTaskListEmpty())
		this->resetBlockLenghtCopy();
}


void MP::Player::_player_automatic_move(Map& aMap, TaskManager& aTaskManager)
{
	if (_path != nullptr and  aPawnObiectTaskManager.isTaskListEmpty())
	{

		MapElement* nextDestination = _path;//Takes new destination (new block).
		MapElement* tmp = aMap.findElementAddressSquareRange(getObiectCoord());//Return element where pawn stands.

		if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x
			and tmp->getLandTile().getObiectCoord().y + _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes down

			aPawnObiectTaskManager.addTask( MP::TaskNode::taskType::taskGoDown);

		else if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x
			and tmp->getLandTile().getObiectCoord().y - _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes up

			aPawnObiectTaskManager.addTask(MP::TaskNode::taskType::taskGoUp);

		else if (tmp->getLandTile().getObiectCoord().x + _block_length == nextDestination->getLandTile().getObiectCoord().x//Goes right
			and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)

			aPawnObiectTaskManager.addTask(MP::TaskNode::taskType::taskGoRight);

		else if (tmp->getLandTile().getObiectCoord().x - _block_length == nextDestination->getLandTile().getObiectCoord().x//Goes left
			and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)

			aPawnObiectTaskManager.addTask(MP::TaskNode::taskType::taskGoLeft);


		_set_path(_path->getNextElement());//Deleting usless element
		delete nextDestination;
	}
	else if(_path == nullptr and aPawnObiectTaskManager.isTaskListEmpty())
		aTaskManager.deleteTaskList();
}



void MP::Player::_set_path(MapElement*& newPath)
{
	_path = newPath;
}


void MP::Player::_player_auto_animation(sf::Clock& globalClock)
{
	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoUp, false))
		_player_animation_up(globalClock);

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoDown, false))
		_player_animation_down(globalClock);

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoLeft, false))
		_player_animation_left(globalClock);

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoRight, false))
		_player_animation_right(globalClock);

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskNone, false))
		_player_animation_idle(globalClock);
}

void MP::Player::_player_auto_move(sf::Clock& globalClock)
{
	MP::Move tmp;

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoUp, false))
		tmp.moveBlockUp(*this, globalClock);

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoLeft, false))
		tmp.moveBlockLeft(*this, globalClock);

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoDown, false))
		tmp.moveBlockDown(*this, globalClock);

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoRight, false))
		tmp.moveBlockRight(*this, globalClock);

	if (aPawnObiectTaskManager.isTaskListEmpty())
		this->resetBlockLenghtCopy();
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
	MapElement *currentBlock = aGameMap.findElementAddressSquareRange(this->getObiectCoord());


	if (currentBlock->getPlace() != nullptr)
	{
		aMainTaskManger.setState(TaskManager::stateType::statePlacesMenu);
		_current_place = currentBlock->getPlace();
	}
}

std::shared_ptr<MP::Places>& MP::Player::getCurrentPlace()
{
	return _current_place;
}

void MP::Player::update(TaskManager& aMainTaskManager, sf::Clock& GameClock, MP::Map& aMap, sf::Vector2f mouseGameCoord)
{
	_procedure_player_auto_or_normal_move(aMainTaskManager, GameClock, aMap, mouseGameCoord);
}

void MP::Player::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
	std::vector<PathIcon> tmpPathCopy = _a_path_icon;
	for (unsigned int i = 0; i < tmpPathCopy.size(); i++)
	{
		mainWindow.draw(tmpPathCopy[i].aAnimation.getObiectSprite());
	}
}

void MP::Player::_procedure_player_auto_or_normal_move(TaskManager& aMainTaskManager, sf::Clock& gameClock, MP::Map& aMap, sf::Vector2f& mouseGameCoord)
{
	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskNormalMove, false))
	{
		_player_move(gameClock, aMainTaskManager);

		_player_animation(gameClock, aMainTaskManager);
	}
	if (!aMainTaskManager.findTask(MP::TaskNode::taskType::taskNormalMove, false) or (!aMainTaskManager.findTask(MP::TaskNode::taskType::taskAutoMove, false)))
		_player_animation_idle(gameClock);

	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskCreateAutoPath, true))
	{
		//geting start and stop coordinates

		MapElement* start = aMap.findElementAddressSquareRange(getObiectCoord());

		MapElement* stop = aMap.findElementAddressSquareRange(mouseGameCoord);

		if (stop->isWalkable())
		{
			if (start->getLandTile().getObiectCoord() != stop->getLandTile().getObiectCoord())
			{

				checkingVector = stop->getLandTile().getObiectCoord();

				//creating path
				MP::PathCreator  tmp(aMap);

				aMainTaskManager.addTask(MP::TaskNode::taskType::taskWaitForDoubleClickLeft); //computer waiting for player reply
				_set_path(tmp.findPath(start->getLandTile().getObiectCoord(), stop->getLandTile().getObiectCoord()));

				_mark_path();
			}
		}
		else
			aMainTaskManager.deleteTaskList();
	}
	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskDoubleClickLeft, true))	//starts procedure auto move if player clicked second time
	{
		MapElement* checkingElement = aMap.findElementAddressSquareRange(mouseGameCoord);

		if (checkingElement->getLandTile().getObiectCoord().x == checkingVector.x and checkingElement->getLandTile().getObiectCoord().y == checkingVector.y) //continue auto move
		{
			_unmark_path();
			aMainTaskManager.addTask(MP::TaskNode::taskType::taskExecuteAutoMove);
		}
		else //break auto move
		{
			_unmark_path();
			aMainTaskManager.addTask(MP::TaskNode::taskType::taskBreakAutoMove);
		}
	}
	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskExecuteAutoMove, false))//execute auto move		
	{
		_player_automatic_move(aMap, aMainTaskManager);
		_player_auto_animation(gameClock);
		_player_auto_move(gameClock);
	}
	if (aMainTaskManager.findTask(MP::TaskNode::taskType::taskBreakAutoMove, false))//breaks auto move
	{
		if (!aPawnObiectTaskManager.isTaskListEmpty())
		{
			_player_auto_animation(gameClock);
			_player_auto_move(gameClock);
		}
		else
		{
			_delete_player_path();
			aMainTaskManager.deleteTaskList();
		}
	}
}
