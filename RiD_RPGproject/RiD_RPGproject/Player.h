#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "MapMove.h"
#include "PawnObiect.h"

namespace MP
{
	class Player :public PawnObiect
	{
	private:


	public:

		Player();

		//############ move animation ##############

		void playerAnimation(sf::Clock& globalClock, MP::TaskManager& aTaskManager);

		void playerAnimationRight(sf::Clock& globalClock);

		void playerAnimationLeft(sf::Clock& globalClock);

		void playerAnimationUp(sf::Clock& globalClock);

		void playerAnimationDown(sf::Clock& globalClock);

		//##########################################
	};


}
#endif