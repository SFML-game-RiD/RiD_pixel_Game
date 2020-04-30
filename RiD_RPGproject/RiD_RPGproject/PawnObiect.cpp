#include "PawnObiect.h"
#include "TaskManager.h"

MP::PawnObiect::PawnObiect()
{
	_stand_land = nullptr;
}

bool MP::PawnObiect::checkGoUp(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.y -= _block_length;
	MapElement* tmp2= aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_stand_land = tmp2;
		return true;
	}
	else
		return false;
}

bool MP::PawnObiect::checkGoDown(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.y += _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_stand_land = tmp2;
		return true;
	}
	else
		return false;
}

bool MP::PawnObiect::checkGoLeft(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.x -= _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_stand_land = tmp2;
		return true;
	}
	else
		return false;
}

bool MP::PawnObiect::checkGoRight(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.x += _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_stand_land = tmp2;
		return true;
	}
	else
		return false;
}

void MP::PawnObiect::tryToMoveUp(Map& aMap, TaskManager& aMainTaskManager)
{
	if (checkGoUp(aMap) and aMainTaskManager.isTaskListEmpty())
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoUp);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

void MP::PawnObiect::tryToMoveDown(Map& aMap, TaskManager& aMainTaskManager)
{
	if (checkGoDown(aMap) and aMainTaskManager.isTaskListEmpty())
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoDown);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

void MP::PawnObiect::tryToMoveLeft(Map& aMap, TaskManager& aMainTaskManager)
{
	if (checkGoLeft(aMap) and aMainTaskManager.isTaskListEmpty())
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoLeft);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

void MP::PawnObiect::tryToMoveRight(Map& aMap, TaskManager& aMainTaskManager)
{
	if (checkGoRight(aMap) and aMainTaskManager.isTaskListEmpty())
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoRight);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

MP::MapElement* MP::PawnObiect::getStandLand()
{
	return _stand_land;
}
