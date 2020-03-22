#include "TaskManager.h"

MP::TaskManager::TaskManager()
{
	
}

MP::TaskManager::taskType MP::TaskManager::getTask()
{
	return _current_task;
}

void MP::TaskManager::startProcedureGoUp()
{
	if(_current_task == taskNone)
	_current_task = taskGoUp;
}

void MP::TaskManager::startProcedureGoDown()
{
	if (_current_task == taskNone)
	_current_task = taskGoDown;
}

void MP::TaskManager::startProcedureGoLeft()
{
	if (_current_task == taskNone)
	_current_task = taskGoLeft;
}

void MP::TaskManager::startProcedureGoRight()
{
	if (_current_task == taskNone)
	_current_task = taskGoRight;
}

void MP::TaskManager::endTask()
{
	_current_task = taskNone;
}
