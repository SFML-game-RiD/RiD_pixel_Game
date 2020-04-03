#ifndef _PLAYER_H_
#define _PLAYER_H_

//#include <SFML/Graphics.hpp>
#include "MapMove.h"
#include "PawnObiect.h"

namespace MP
{
	class Player :public PawnObiect
	{
	private:


	public:

		Player(sf::Texture *texturePtr);

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