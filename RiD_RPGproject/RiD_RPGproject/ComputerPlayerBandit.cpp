#include "ComputerPlayerBandit.h"
#include "Move.h"


void MP::ComputerPlayerBandit::_chose_destination(Map &aMap)
{
	MP::PathCreator tmp(aMap);
	sf::Vector2f destinationCoord = aMap.returnRandomWalkableElement()->getLandTile().getObiectCoord();
	MapElement* startingElement = aMap.findElementAddressSquareRange(getObiectCoord(), aMap.getMapElementList());

	while(destinationCoord == startingElement->getLandTile().getObiectCoord())
		destinationCoord = aMap.returnRandomWalkableElement()->getLandTile().getObiectCoord();

	//Chose random destination and calculate path.
	
	_path =  tmp.findPath(startingElement->getLandTile().getObiectCoord(),destinationCoord);
}

void MP::ComputerPlayerBandit::_delete_path()
{
	if (_path == nullptr)
		return;
	else
	{
		while (_path != nullptr)
		{
			MapElement* tmp = _path;

			_path = _path->getNextElementCopy();
			delete tmp;
		}
	}
}

bool MP::ComputerPlayerBandit::_check_enemy(std::shared_ptr<Player>& aPlayer)
{
	if (!_is_enemys_check and _stand_land!=nullptr)
	{
		MapElement* SL = _stand_land;
		MapElement* PCL = aPlayer->getStandLand();
		MapElement* SLup = _stand_land->getUpPtrCopy();
		MapElement* SLdown = _stand_land->getDownPtrCopy();
		MapElement* SLleft = _stand_land->getLeftPtrCopy();
		MapElement* SLright = _stand_land->getRightPtrCopy();

		_is_enemys_check = true;

		if (SL == PCL or SL->getDownPtrCopy() == PCL or SL->getRightPtrCopy() == PCL or SL->getLeftPtrCopy() == PCL or SL->getUpPtrCopy() == PCL)
			return true;

		if (SLup->getRightPtrCopy() == PCL or SLup->getLeftPtrCopy() == PCL or SLup->getUpPtrCopy() == PCL)
			return true;

		if (SLdown->getDownPtrCopy() == PCL or SLdown->getRightPtrCopy() == PCL or SLdown->getLeftPtrCopy() == PCL)
			return true;

		if (SLleft->getLeftPtrCopy() == PCL or SLright->getRightPtrCopy() == PCL)
			return true;
	}
	return false;
}

void MP::ComputerPlayerBandit::_get_next_task(Map& aMap)
{
	if (aPawnObiectTaskManager.isTaskListEmpty())
	{
		if (_path == nullptr)//Sets new destination.
		_chose_destination(aMap);

		MapElement* nextDestination = _path;//Takes new destination (new block).
		MapElement* tmp = aMap.findElementAddressSquareRange(getObiectCoord(), aMap.getMapElementList());//Return element where computer player stands.

		_stand_land = tmp;
		_is_enemys_check = false;

		if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x and tmp->getLandTile().getObiectCoord().y + _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes down
			aPawnObiectTaskManager.addTask(MP::TaskNode::taskType::taskGoDown);

		else if (tmp->getLandTile().getObiectCoord().x == nextDestination->getLandTile().getObiectCoord().x and tmp->getLandTile().getObiectCoord().y - _block_length == nextDestination->getLandTile().getObiectCoord().y)//Goes up
			aPawnObiectTaskManager.addTask(MP::TaskNode::taskType::taskGoUp);

		else if (tmp->getLandTile().getObiectCoord().x + _block_length == nextDestination->getLandTile().getObiectCoord().x and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)
			aPawnObiectTaskManager.addTask(MP::TaskNode::taskType::taskGoRight);

		else if (tmp->getLandTile().getObiectCoord().x - _block_length == nextDestination->getLandTile().getObiectCoord().x and tmp->getLandTile().getObiectCoord().y == nextDestination->getLandTile().getObiectCoord().y)
			aPawnObiectTaskManager.addTask(MP::TaskNode::taskType::taskGoLeft);

		_path = _path->getNextElement();//Deleting usless element
		delete nextDestination;	
	}
}

void MP::ComputerPlayerBandit::_computer_player_move(sf::Clock& globalClock)
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

MP::ComputerPlayerBandit::ComputerPlayerBandit(sf::Texture* texturePtr)
{

	_path = nullptr;
	_is_enemys_check = false;
	//Loading textures.
	aAnimation.loadObiectTextures(texturePtr, 4, 4, 64);
	aAnimation.changeSprite(6);
	aAnimation.setScale(0.8, 0.8);

	//Getting computer player animation and move sleep time.
	active_obj_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("computer player", "SleepTime"));
	_obj_animation_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("computer player", "animationSleepTime"));

	//Loading velocity.
	_velocity = RiD::ConfigurationLoader::getIntData("computer player", "velocity");

	//Getting player coordinates.
	setObiectCoord(RiD::ConfigurationLoader::getIntData("computer player", "coordinateX"), RiD::ConfigurationLoader::getIntData("computer player", "coordinateY"));
}

MP::ComputerPlayerBandit::~ComputerPlayerBandit()
{
	_delete_path();
}

void MP::ComputerPlayerBandit::_computer_player_animation(sf::Clock& globalClock)
{
	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoUp, false))
		_computer_player_animation_up(globalClock);

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoDown, false))
		_computer_player_animation_down(globalClock);

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoLeft, false))
		_computer_player_animation_left(globalClock);

	if (aPawnObiectTaskManager.findTask(MP::TaskNode::taskType::taskGoRight, false))
		_computer_player_animation_right(globalClock);
}

void MP::ComputerPlayerBandit::_computer_player_animation_right(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(8, 11);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::_computer_player_animation_left(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(4, 7);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::_computer_player_animation_up(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(12, 15);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::_computer_player_animation_down(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(0, 3);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::update(Map& aMap, sf::Clock& gameClock, std::shared_ptr<Player>& aPlayer)
{
	if (_check_enemy(aPlayer))
		std::cout << " WYKRYLEM GRACZA \n" << std::endl;
	_get_next_task(aMap);
	_computer_player_animation(gameClock);
	_computer_player_move(gameClock);
}

void MP::ComputerPlayerBandit::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
}