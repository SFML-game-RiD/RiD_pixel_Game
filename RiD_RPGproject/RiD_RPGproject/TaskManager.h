#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <set>
#include <iostream>
#include "TaskNode.h"

namespace MP
{
	class TaskManager
	{
	public:

		enum class stateType
		{
			stateGame,
			stateMainMenu,
			statePlacesMenu,
			stateMarketPlace
		};

	private:

		stateType _game_state;

		std::set<std::shared_ptr<TaskNode>> _task_list;

	public:

		TaskManager();

		void setState(stateType aNewStateType);

		stateType getCurrentState();

		bool findTask(TaskNode::taskType aTaskType, bool erase);

		void addTask(TaskNode::taskType newTask);

		void deleteTaskList();

		std::set<std::shared_ptr<TaskNode>>& getTaskList();

		bool isTaskListEmpty();

		void updateState();

		void keyboardHandling();

		void resetInput();
	};
}

#endif // !_TASKMANAGER_H_