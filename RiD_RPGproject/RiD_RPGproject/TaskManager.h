#ifndef _TASKMANAGER_H_
#define _TASKMANAGER_H_

namespace MP
{
	class TaskManager
	{
	public:

	enum taskType
		{
			taskNone,
			taskGoUp,
			taskGoDown,
			taskGoRight,
			taskGoLeft,
		};

	private:

		taskType _current_task;

	public:

		TaskManager();

		taskType getTask();

		void startProcedureGoUp();

		void startProcedureGoDown();

		void startProcedureGoLeft();

		void startProcedureGoRight();

		void endTask();
	};
}

#endif // !_TASKMANAGER_H_