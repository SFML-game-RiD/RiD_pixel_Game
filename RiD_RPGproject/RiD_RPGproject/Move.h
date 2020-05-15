#ifndef MAPMOVE_H
#define MAPMOVE_H

#include "PawnObject.h"
#include "TaskManager.h"
#include "Player.h"

namespace MP
{
	class Move
	{
	private:

		void _move_pixel_down(ActiveObject& obiect);

		void _move_pixel_up(ActiveObject& obiect);

		void _move_pixel_right(ActiveObject& obiect);

		void _move_pixel_left(ActiveObject& obiect);

	public:

		void moveBlockDown(PawnObject& obiect, sf::Clock &currentTime);

		void moveBlockUp(PawnObject& obiect, sf::Clock &currentTime);

		void moveBlockRight(PawnObject& obiect, sf::Clock &currentTime);

		void moveBlockLeft(PawnObject& obiect, sf::Clock &currentTime);


		void moveBlockDown(Player& player, sf::Clock& currentTime,TaskManager &aMainTaskManager);

		void moveBlockUp(Player& player, sf::Clock& currentTime, TaskManager& aMainTaskManager);

		void moveBlockRight(Player& player, sf::Clock& currentTime, TaskManager& aMainTaskManager);

		void moveBlockLeft(Player& player, sf::Clock& currentTime, TaskManager& aMainTaskManager);

		//Checks if main task manager is empty.
		//@param gameMap game's map.
		//@param aMainTaskManager game's task manager.
		void tryToMoveUp(PawnObject& pawn, Map& gameMap, TaskManager& aMainTaskManager);

		//Checks if main task manager is empty.
		//@param gameMap game's map.
		//@param aMainTaskManager game's task manager.
		void tryToMoveDown(PawnObject& pawn, Map& gameMap, TaskManager& aMainTaskManager);

		//Checks if main task manager is empty.
		//@param gameMap game's map.
		//@param aMainTaskManager game's task manager.
		void tryToMoveLeft(PawnObject& pawn, Map& gameMap, TaskManager& aMainTaskManager);

		//Checks if main task manager is empty.
		//@param gameMap game's map.
		//@param aMainTaskManager game's task manager.
		void tryToMoveRight(PawnObject& pawn, Map& gameMap, TaskManager& aMainTaskManager);
	};
}
#endif