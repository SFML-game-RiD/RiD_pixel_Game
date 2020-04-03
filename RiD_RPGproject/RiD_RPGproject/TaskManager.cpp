#include "TaskManager.h"

MP::TaskManager::TaskManager()
{
	_current_task = taskNone;
}

MP::TaskManager::taskType MP::TaskManager::getTask()
{
	return _current_task;
}

void MP::TaskManager::startProcedureGoUp(PawnObiect& pawn, MP::Map& aMap)
{
	if (_current_task == taskNone)
	{
		if (pawn.checkGoUp(aMap))
		_current_task = taskGoUp;
	}
}

void MP::TaskManager::startProcedureGoDown(PawnObiect& pawn, MP::Map& aMap)
{
	if (_current_task == taskNone)
	{
		if (pawn.checkGoDown(aMap))
		_current_task = taskGoDown;
	}
}

void MP::TaskManager::startProcedureGoLeft(PawnObiect& pawn, MP::Map& aMap)
{
	if (_current_task == taskNone)
	{
		if (pawn.checkGoLeft(aMap))
		_current_task = taskGoLeft;
	}
}

void MP::TaskManager::startProcedureGoRight(PawnObiect& pawn, MP::Map& aMap)
{
	if (_current_task == taskNone)
	{
		if(pawn.checkGoRight(aMap))
		_current_task = taskGoRight;
	}
}

void MP::TaskManager::startProcedureZoomIn()
{
	if (_current_task == taskNone)
	{
		_current_task = zoomIn;
	}
}

void MP::TaskManager::startProcedureZoomOut()
{
	if (_current_task == taskNone)
	{
		_current_task = zoomOut;
	}
}

void MP::TaskManager::endTask()
{
	_current_task = taskNone;
}
