#ifndef  _CONPUTER_PLAYER_H_
#define _CONPUTER_PLAYER_H_

#include <SFML/Graphics.hpp>
#include "TaskManager.h"
#include "PawnObiect.h"
#include "pathCreator.h"

namespace MP
{
	class ComputerPlayer:public PawnObiect
	{
	private:

		MapElement* _path;

	public:

		TaskManager computerTasks;

		ComputerPlayer(sf::Texture* texturePtr);

		//############ move animation ##############

		void computerPlayerAnimation(sf::Clock& globalClock);

		void computerPlayerAnimationRight(sf::Clock& globalClock);

		void computerPlayerAnimationLeft(sf::Clock& globalClock);

		void computerPlayerAnimationUp(sf::Clock& globalClock);

		void computerPlayerAnimationDown(sf::Clock& globalClock);

		//##########################################

		void choseDestination(Map& aMap);

		void getNextTask(Map& aMap);

		void computerPlayerMove(sf::Clock& globalClock);
	};

}
#endif // ! _CONPUTER_PLAYER_H_