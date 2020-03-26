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

		void movePixelDown(ActiveObiect& obiect);

		void movePixelUp(ActiveObiect& obiect);

		void movePixelRight(ActiveObiect& obiect);

		void movePixelLeft(ActiveObiect& obiect);

	public:

		void moveBlockDown(ActiveObiect& obiect, sf::Clock &currentTime,TaskManager & aTaskManager);

		void moveBlockUp(ActiveObiect& obiect, sf::Clock &currentTime, TaskManager& aTaskManager);

		void moveBlockRight(ActiveObiect& obiect, sf::Clock &currentTime, TaskManager& aTaskManager);

		void moveBlockLeft(ActiveObiect& obiect, sf::Clock &currentTime, TaskManager& aTaskManager);
	};
}
#endif