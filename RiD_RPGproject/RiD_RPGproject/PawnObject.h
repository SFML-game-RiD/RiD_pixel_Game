#pragma once
#include "ActiveObject.h"
#include "Map.h"
#include "TaskManager.h"

namespace MP 
{
	class PawnObject:public ActiveObject
	{
	protected:

		MapElement* _current_land;///Stores ptr to current land, where pawn stands.

		//Checks if up map element is walkable.
		//@param gameMap game's map.
		bool _check_go_up(Map& gameMap);

		//Checks if up map element is walkable.
		//@param gameMap game's map.
		bool _check_go_down(Map& gameMap);

		//Checks if up map element is walkable.
		//@param gameMap game's map.
		bool _check_go_left(Map& gameMap);

		//Checks if up map element is walkable.
		//@param gameMap game's map.
		bool _check_go_right(Map& gameMap);

	public:

		TaskManager aPawnObjectTaskManager;///Special task manager for pawns.
		
		//Pawn's constructor.
		PawnObject();

		//Checks if main task manager is empty.
		//@param gameMap game's map.
		//@param aMainTaskManager game's task manager.
		void tryToMoveUp(Map& gameMap, TaskManager& aMainTaskManager);

		//Checks if main task manager is empty.
		//@param gameMap game's map.
		//@param aMainTaskManager game's task manager.
		void tryToMoveDown(Map& gameMap, TaskManager& aMainTaskManager);

		//Checks if main task manager is empty.
		//@param gameMap game's map.
		//@param aMainTaskManager game's task manager.
		void tryToMoveLeft(Map& gameMap, TaskManager& aMainTaskManager);

		//Checks if main task manager is empty.
		//@param gameMap game's map.
		//@param aMainTaskManager game's task manager.
		void tryToMoveRight(Map& gameMap,TaskManager &aMainTaskManager);

		//Returns current land, where pawn stands.
		//@return current land.
		MapElement* getCurrentLand();
	};
}
