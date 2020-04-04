#ifndef  _CONPUTER_PLAYER_H_
#define _CONPUTER_PLAYER_H_

#include <SFML/Graphics.hpp>
#include "TaskManager.h"
#include "PawnObiect.h"

namespace MP
{
	class ComputerPlayer:public PawnObiect
	{
	public:

		ComputerPlayer(sf::Texture* texturePtr);

		//############ move animation ##############

		void computerPlayerAnimation(sf::Clock& globalClock, MP::TaskManager& aTaskManager);

		void computerPlayerAnimationRight(sf::Clock& globalClock);

		void computerPlayerAnimationLeft(sf::Clock& globalClock);

		void computerPlayerAnimationUp(sf::Clock& globalClock);

		void computerPlayerAnimationDown(sf::Clock& globalClock);

		//##########################################
	};

}
#endif // ! _CONPUTER_PLAYER_H_