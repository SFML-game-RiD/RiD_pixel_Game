#include "PawnObject.h"
#include "TaskManager.h"

MP::PawnObject::PawnObject()
{
	_current_land = nullptr;
	_sound_player.setSpeed(1.15);
	_whinney_once = false;
}

bool MP::PawnObject::_check_go_up(MP::Map& aMap)
{
	sf::Vector2f tmp = getObjectCoord();
	tmp.y -= _block_length;
	MapElement* tmp2= aMap.findElementAddressSquareRange(tmp);
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_current_land = tmp2;
		return true;
	}
	else
		return false;
}

bool MP::PawnObject::_check_go_down(MP::Map& aMap)
{
	sf::Vector2f tmp = getObjectCoord();
	tmp.y += _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp);
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_current_land = tmp2;
		return true;
	}
	else
		return false;
}

bool MP::PawnObject::_check_go_left(MP::Map& aMap)
{
	sf::Vector2f tmp = getObjectCoord();
	tmp.x -= _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp);
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_current_land = tmp2;
		return true;
	}
	else
		return false;
}

bool MP::PawnObject::_check_go_right(MP::Map& aMap)
{
	sf::Vector2f tmp = getObjectCoord();
	tmp.x += _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp);
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_current_land = tmp2;
		return true;
	}
	else
		return false;
}

void MP::PawnObject::tryToMoveUp(Map& aMap, TaskManager& aMainTaskManager)
{
	if (_check_go_up(aMap))
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoUp);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

void MP::PawnObject::tryToMoveDown(Map& aMap, TaskManager& aMainTaskManager)
{
	if (_check_go_down(aMap) )
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoDown);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

void MP::PawnObject::tryToMoveLeft(Map& aMap, TaskManager& aMainTaskManager)
{
	if (_check_go_left(aMap) )
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoLeft);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

void MP::PawnObject::tryToMoveRight(Map& aMap, TaskManager& aMainTaskManager)
{
	if (_check_go_right(aMap) )
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoRight);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

MP::MapElement* MP::PawnObject::getCurrentLand()
{
	return _current_land;
}
