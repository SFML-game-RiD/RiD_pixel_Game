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
	_current_task = taskGoUp;
}

void MP::TaskManager::startProcedureGoDown()
{
	_current_task = taskGoUp;
}

void MP::TaskManager::startProcedureGoLeft()
{
	_current_task = taskGoUp;
}

void MP::TaskManager::startProcedureGoRight()
{
	_current_task = taskGoUp;
}

void MP::TaskManager::endTask()
{
	_current_task = taskNone;
}
