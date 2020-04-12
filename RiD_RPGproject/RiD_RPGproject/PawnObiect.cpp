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
	if(aMainTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskNone
		and aMainTaskManager.getTask(MP::TaskManager::taskRange::reply) == MP::TaskManager::taskType::taskNone
		and aMainTaskManager.getTask(MP::TaskManager::taskRange::mainOrder) == MP::TaskManager::taskType::taskNone)
	{
		if (checkGoUp(aMap))
		{
			aMainTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskGoUp);
			aMainTaskManager.setTask(MP::TaskManager::taskRange::mainOrder, MP::TaskManager::taskType::taskNormalMove);
		}
	}
}

void MP::PawnObiect::tryToMoveDown(Map& aMap, TaskManager& aMainTaskManager)
{
	if (aMainTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskNone
		and aMainTaskManager.getTask(MP::TaskManager::taskRange::reply) == MP::TaskManager::taskType::taskNone
		and aMainTaskManager.getTask(MP::TaskManager::taskRange::mainOrder) == MP::TaskManager::taskType::taskNone)
	{
		if (checkGoDown(aMap))
		{
			aMainTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskGoDown);
			aMainTaskManager.setTask(MP::TaskManager::taskRange::mainOrder, MP::TaskManager::taskType::taskNormalMove);
		}
	}
}

void MP::PawnObiect::tryToMoveLeft(Map& aMap, TaskManager& aMainTaskManager)
{
	if ( aMainTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskNone
		and aMainTaskManager.getTask(MP::TaskManager::taskRange::reply) == MP::TaskManager::taskType::taskNone
		and aMainTaskManager.getTask(MP::TaskManager::taskRange::mainOrder) == MP::TaskManager::taskType::taskNone)
	{ 
		if (checkGoLeft(aMap))
		{
			aMainTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskGoLeft);
			aMainTaskManager.setTask(MP::TaskManager::taskRange::mainOrder, MP::TaskManager::taskType::taskNormalMove);
		}
	}
}

void MP::PawnObiect::tryToMoveRight(Map& aMap, TaskManager& aMainTaskManager)
{
	if (aMainTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskNone
		and aMainTaskManager.getTask(MP::TaskManager::taskRange::reply) == MP::TaskManager::taskType::taskNone
		and aMainTaskManager.getTask(MP::TaskManager::taskRange::mainOrder) == MP::TaskManager::taskType::taskNone)
	{
		if (checkGoRight(aMap))
		{
			aMainTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskGoRight);
			aMainTaskManager.setTask(MP::TaskManager::taskRange::mainOrder, MP::TaskManager::taskType::taskNormalMove);
		}
	}
}
