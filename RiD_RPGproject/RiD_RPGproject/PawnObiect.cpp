#include "PawnObiect.h"
#include "TaskManager.h"

bool MP::PawnObiect::checkGoUp(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.y -= _block_length;
	MapElement* tmp2= aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
		return true;
	else
		return false;
}

bool MP::PawnObiect::checkGoDown(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.y += _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
		return true;
	else
		return false;
}

bool MP::PawnObiect::checkGoLeft(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.x -= _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
		return true;
	else
		return false;
}

bool MP::PawnObiect::checkGoRight(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.x += _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
		return true;
	else
		return false;
}

void MP::PawnObiect::tryToMoveUp(Map& aMap, TaskManager& aMainTaskManager)
{
	if (checkGoUp(aMap))
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoUp);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

void MP::PawnObiect::tryToMoveDown(Map& aMap, TaskManager& aMainTaskManager)
{
	if (checkGoDown(aMap))
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoDown);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

void MP::PawnObiect::tryToMoveLeft(Map& aMap, TaskManager& aMainTaskManager)
{
	if (checkGoLeft(aMap))
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoLeft);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}

void MP::PawnObiect::tryToMoveRight(Map& aMap, TaskManager& aMainTaskManager)
{
	if (checkGoRight(aMap))
	{
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskGoRight);
		aMainTaskManager.addTask(MP::TaskNode::taskType::taskNormalMove);
	}
}
