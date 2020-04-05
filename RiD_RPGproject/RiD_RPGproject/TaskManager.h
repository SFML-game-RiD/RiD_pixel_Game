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
			taskZoomOut
		};

	private:

		taskType _current_task;

	public:

		TaskManager();

		taskType getTask();

		void startProcedureGoUp(PawnObiect & pawn,MP::Map &aMap);

		void startProcedureGoDown(PawnObiect& pawn, MP::Map& aMap);

		void startProcedureGoLeft(PawnObiect& pawn, MP::Map& aMap);

		void startProcedureGoRight(PawnObiect& pawn, MP::Map& aMap);

		void startProcedureZoomIn();

		void startProcedureZoomOut();

		void endTask();
	};
}

#endif // !_TASKMANAGER_H_