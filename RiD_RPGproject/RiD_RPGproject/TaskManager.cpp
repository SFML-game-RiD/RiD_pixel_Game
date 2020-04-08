#include "TaskManager.h"

MP::TaskManager::TaskManager()
{
	_current_task = taskNone;
	_mouse_task = taskNone;
}

MP::TaskManager::taskType MP::TaskManager::getTask()
{
	return _current_task;
}

MP::TaskManager::taskType MP::TaskManager::getMouseTask()
{
	return _mouse_task;
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
		_current_task = taskZoomIn;
	}
}

void MP::TaskManager::startProcedureZoomOut()
{
	if (_current_task == taskNone)
	{
		_current_task = taskZoomOut;}
}

void MP::TaskManager::startProcedureClickLeft()
{
	if ((_mouse_task == taskNone and _current_task == taskNone) or  _current_task == taskAutoMove)
	{
		_mouse_task = taskClickLeft;
	}
	else if (_mouse_task == taskWaitForDoubleClickLeft)
	{
		_mouse_task = taskDoubleClickLeft;
	}
}

void MP::TaskManager::endTask()
{
	_current_task = taskNone;
}

void MP::TaskManager::endMouseTask()
{
	_mouse_task = taskNone;
}

void MP::TaskManager::startProcedureAutoMove()
{
	if (_mouse_task == taskDoubleClickLeft)
	{
		_current_task = taskAutoMove;
	}
}

void MP::TaskManager::startProcedureWaitForDoubleClick()
{
	if (_mouse_task == taskClickLeft)
	{
		_mouse_task = taskWaitForDoubleClickLeft;
	}
}
