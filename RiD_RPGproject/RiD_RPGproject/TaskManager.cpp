#include "TaskManager.h"

MP::TaskManager::TaskManager()
{
	_game_state = taskType:: taskNone;
	_game_order = taskType::taskNone;
	_game_reply = taskType::taskNone;
	_game_main_order = taskType::taskNone;

}

MP::TaskManager::taskType MP::TaskManager::getTask(taskRange aTaskRange)
{
	switch (aTaskRange) {
	case(taskRange::state):
	{
		return _game_state;
	}break;
	case(taskRange::order):
	{
		return _game_order;
	}break;
	case(taskRange::reply):
	{
		return _game_reply;
	}break;
	case(taskRange::mainOrder):
	{
		return _game_main_order;
	}break;
	}
}

void MP::TaskManager::endTask(taskRange aTaskRange)
{
	switch (aTaskRange) {
	case(taskRange::state):
	{
		_game_state = taskType::taskNone;
	}break;
	case(taskRange::order):
	{
		_game_order = taskType::taskNone;
	}break;
	case(taskRange::reply):
	{
		_game_reply = taskType::taskNone;
	}break;
	case(taskRange::mainOrder):
	{
		_game_main_order = taskType::taskNone;
	}break;
	}
}

void MP::TaskManager::setTask(taskRange aTaskRange, taskType typeOfTask)
{
	switch (aTaskRange) {
	case(taskRange::state):
	{
		_game_state = typeOfTask;
	}break;
	case(taskRange::order):
	{
		_game_order = typeOfTask;
	}break;
	case(taskRange::reply):
	{
		_game_reply = typeOfTask;
	}break;
	case(taskRange::mainOrder):
	{
		_game_main_order = typeOfTask;
	}break;
	}
}

void MP::TaskManager::resetOrdersAndReply()
{
	_game_main_order = taskType::taskNone;
	_game_order = taskType::taskNone;
	_game_reply = taskType::taskNone;
}

