#ifndef _PAWNOBIECT_H_
#define _PAWNOBIECT_H_

#include "SFML/Graphics.hpp"
#include "ActiveObiect.h"
#include "TaskManager.h"
#include <vector>

namespace MP 
{
	class PawnObiect:public ActiveObiect
	{
	private:


	public:
		
		PawnObiect();

		void pawnAnimation(sf::Clock & globalClock, MP::TaskManager& aTaskManager);

		void pawnAnimationRight(sf::Clock & globalClock);

		void pawnAnimationLeft(sf::Clock & globalClock);

		void pawnAnimationUp(sf::Clock & globalClock);

		void pawnAnimationDown(sf::Clock & globalClock);
		
		void setNextSprite(int from, int to);
	};
}
#endif
