#ifndef _TASKMANAGER_H_
#define _TASKMANAGER_H_

#include "PawnObiect.h"
#include "Map.h"

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

			taskZoomIn,
			taskZoomOut,

			//Mouse tasks

			taskClickLeft,
			taskClickRight,
			taskDoubleClickLeft,
			taskWaitForDoubleClickLeft,

			//Auto move tasks

			taskAutoMove
		};

	private:

		taskType _current_task;

		taskType _mouse_task;

		//new task required
	public:

		TaskManager();

		taskType getTask();

		taskType getMouseTask();

		void endTask();

		void endMouseTask();

		void startProcedureGoUp(PawnObiect & pawn,MP::Map &aMap);

		void startProcedureGoDown(PawnObiect& pawn, MP::Map& aMap);

		void startProcedureGoLeft(PawnObiect& pawn, MP::Map& aMap);

		void startProcedureGoRight(PawnObiect& pawn, MP::Map& aMap);

		void startProcedureZoomIn();

		void startProcedureZoomOut();

		void startProcedureClickLeft();

		void startProcedureAutoMove();

		void startProcedureWaitForDoubleClick();
	};
}

#endif // !_TASKMANAGER_H_