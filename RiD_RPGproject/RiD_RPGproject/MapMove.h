#ifndef _MAPMOVE_H_
#define _MAPMOVE_H_

#include "ActiveObiect.h"
#include "TaskManager.h"
#include "Player.h"

namespace MP
{
	class MapMove
	{
	private:
		


	public:

		//void startProcedurePlayerMove(TaskManager & aTaskManager, Player &aPlayer, sf::Clock &aGameClock);

		void moveBlockDown(ActiveObiect& obiect, sf::Clock currentTime);

		void moveBlockUp(ActiveObiect& obiect, sf::Clock currentTime);

		void moveBlockRight(ActiveObiect& obiect, sf::Clock currentTime);

		void moveBlockLeft(ActiveObiect& obiect, sf::Clock currentTime);

		void movePixelDown(ActiveObiect& obiect);

		void movePixelUp(ActiveObiect& obiect);

		void movePixelRight(ActiveObiect& obiect);

		void movePixelLeft(ActiveObiect& obiect);
	};
}
#endif