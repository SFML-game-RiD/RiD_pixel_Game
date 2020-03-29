#ifndef _TASKMANAGER_H_
#define _TASKMANAGER_H_

#include "Obiect.h"

namespace MP
{
	class TaskManager
	{
	public:

	enum taskType
		{
			//Move tasks

			taskNone,
			taskGoUp,
			taskGoDown,
			taskGoRight,
			taskGoLeft,

			//Camera tasks

			zoomIn,
			zoomOut
		};

	private:

		taskType _current_task;

	public:

		TaskManager();

		taskType getTask();

		void startProcedureGoUp(Obiect & pawn);

		void startProcedureGoDown(Obiect& pawn);

		void startProcedureGoLeft(Obiect& pawn);

		void startProcedureGoRight(Obiect& pawn);

		void startProcedureZoomIn();

		void startProcedureZoomOut();

		void endTask();
	};
}

#endif // !_TASKMANAGER_H_