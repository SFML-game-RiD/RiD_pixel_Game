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

		bool _whinney_once;

	public:

		TaskManager aPawnObjectTaskManager;///Special task manager for pawns.
		
		//Pawn's constructor.
		PawnObject();


		//Checks if up map element is walkable.
		//@param gameMap game's map.
		bool checkGoUp(Map& gameMap);

		//Checks if up map element is walkable.
		//@param gameMap game's map.
		bool checkGoDown(Map& gameMap);

		//Checks if up map element is walkable.
		//@param gameMap game's map.
		bool checkGoLeft(Map& gameMap);

		//Checks if up map element is walkable.
		//@param gameMap game's map.
		bool checkGoRight(Map& gameMap);

		//Returns current land, where pawn stands.
		//@return current land.
		MapElement* getCurrentLand();
	};
}
