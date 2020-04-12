#ifndef _MAPMOVE_H_
#define _MAPMOVE_H_

#include "PawnObiect.h"
#include "TaskManager.h"
#include "Player.h"

namespace MP
{
	class Move
	{
	private:

		void movePixelDown(ActiveObiect& obiect);

		void movePixelUp(ActiveObiect& obiect);

		void movePixelRight(ActiveObiect& obiect);

		void movePixelLeft(ActiveObiect& obiect);

	public:

		void moveBlockDown(PawnObiect& obiect, sf::Clock &currentTime);

		void moveBlockUp(PawnObiect& obiect, sf::Clock &currentTime);

		void moveBlockRight(PawnObiect& obiect, sf::Clock &currentTime);

		void moveBlockLeft(PawnObiect& obiect, sf::Clock &currentTime);


		void moveBlockDown(Player& obiect, sf::Clock& currentTime,TaskManager &aMainTaskManager);

		void moveBlockUp(Player& obiect, sf::Clock& currentTime, TaskManager& aMainTaskManager);

		void moveBlockRight(Player& obiect, sf::Clock& currentTime, TaskManager& aMainTaskManager);

		void moveBlockLeft(Player& obiect, sf::Clock& currentTime, TaskManager& aMainTaskManager);
	};
}
#endif