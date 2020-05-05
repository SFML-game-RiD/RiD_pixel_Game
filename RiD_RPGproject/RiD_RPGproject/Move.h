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

		void movePixelDown(ActiveObject& obiect);

		void movePixelUp(ActiveObject& obiect);

		void movePixelRight(ActiveObject& obiect);

		void movePixelLeft(ActiveObject& obiect);

	public:

		void moveBlockDown(PawnObject& obiect, sf::Clock &currentTime);

		void moveBlockUp(PawnObject& obiect, sf::Clock &currentTime);

		void moveBlockRight(PawnObject& obiect, sf::Clock &currentTime);

		void moveBlockLeft(PawnObject& obiect, sf::Clock &currentTime);


		void moveBlockDown(Player& player, sf::Clock& currentTime,TaskManager &aMainTaskManager);

		void moveBlockUp(Player& player, sf::Clock& currentTime, TaskManager& aMainTaskManager);

		void moveBlockRight(Player& player, sf::Clock& currentTime, TaskManager& aMainTaskManager);

		void moveBlockLeft(Player& player, sf::Clock& currentTime, TaskManager& aMainTaskManager);
	};
}
#endif