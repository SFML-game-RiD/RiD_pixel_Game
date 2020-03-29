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
	}
}

void MP::TaskManager::startProcedureGoDown(Obiect& pawn)
{
	if (_current_task == taskNone)
	{
		_current_task = taskGoDown;
	}
}

void MP::TaskManager::startProcedureGoLeft(Obiect& pawn)
{
	if (_current_task == taskNone)
	{
		_current_task = taskGoLeft;
	}
}

void MP::TaskManager::startProcedureGoRight(Obiect& pawn)
{
	if (_current_task == taskNone)
	{
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
