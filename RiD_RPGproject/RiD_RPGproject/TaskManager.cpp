#include "TaskManager.h"

MP::TaskManager::TaskManager()
{
	_game_state = stateType::stateMainMenu;
}


void MP::TaskManager::setState(stateType aNewStateType)
{
	_game_state = aNewStateType;
}

MP::TaskManager::stateType MP::TaskManager::getCurrentState()
{
	return _game_state;
}


bool MP::TaskManager::findTask(TaskNode::taskType aTaskType, bool erase)
{
	if (!taskList.empty())
	{
		std::set<std::shared_ptr<MP::TaskNode>>::iterator findTask;
		findTask = taskList.begin();
		for (findTask; findTask != taskList.end(); findTask++)
		{
			if ((*findTask)->getTask() == aTaskType)
			{
				if (erase)
					taskList.erase(*findTask);

					return true;
			}
		}
	}
	return false;
}

void MP::TaskManager::addTask(TaskNode::taskType newTask)
{
	if (!findTask(TaskNode::taskType::taskNormalMove,false)and !findTask(newTask, false))
	{
		std::shared_ptr<TaskNode> tmp = std::make_shared<TaskNode>(newTask);
		taskList.insert(tmp);
	}
}

void MP::TaskManager::deleteTaskList()
{
	taskList.clear();
}

std::set<std::shared_ptr<MP::TaskNode>>& MP::TaskManager::getTaskList()
{
	return taskList;
}

bool MP::TaskManager::isTaskListEmpty()
{
	return taskList.empty();
}

