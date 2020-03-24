#include "TaskManager.h"

MP::TaskManager::TaskManager()
{
	
}

MP::TaskManager::taskType MP::TaskManager::getTask()
{
	return _current_task;
}

void MP::TaskManager::startProcedureGoUp(Obiect& pawn)
{
	if (_current_task == taskNone)
	{
		_current_task = taskGoUp;
		pawn.animationMaker.changeSprite(10);
	}
}

void MP::TaskManager::startProcedureGoDown(Obiect& pawn)
{
	if (_current_task == taskNone)
	{
		_current_task = taskGoDown;
		pawn.animationMaker.changeSprite(1);
	}
}

void MP::TaskManager::startProcedureGoLeft(Obiect& pawn)
{
	if (_current_task == taskNone)
	{
		_current_task = taskGoLeft;
		pawn.animationMaker.changeSprite(4);
	}
}

void MP::TaskManager::startProcedureGoRight(Obiect& pawn)
{
	if (_current_task == taskNone)
	{
		_current_task = taskGoRight;
		pawn.animationMaker.changeSprite(7);
	}
}

void MP::TaskManager::endTask()
{
	{_current_task = taskNone;

	}
}
