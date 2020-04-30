#ifndef PAWNOBIECT_H
#define PAWNOBIECT_H

#include "ActiveObiect.h"
#include "Map.h"
#include "TaskManager.h"

namespace MP 
{
	class PawnObiect:public ActiveObiect
	{
	protected:

		MapElement* _stand_land;

	public:

		TaskManager aPawnObiectTaskManager;
		
		PawnObiect();

		bool checkGoUp(Map & aMap);

		bool checkGoDown(Map & aMap);

		bool checkGoLeft(Map & aMap);

		bool checkGoRight(Map & aMap);

		void tryToMoveUp(Map& aMap, TaskManager& aMainTaskManager);

		void tryToMoveDown(Map& aMap, TaskManager& aMainTaskManager);

		void tryToMoveLeft(Map& aMap, TaskManager& aMainTaskManager);

		void tryToMoveRight(Map& aMap,TaskManager &aMainTaskManager);

		MapElement* getStandLand();
	};
}
#endif
