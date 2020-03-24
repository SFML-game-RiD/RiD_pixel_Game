#ifndef _ACTIVEOBIECT_H_
#define _ACTIVEOBIECT_H_

#include "Obiect.h"

namespace MP
{
	class ActiveObiect :public Obiect
	{
	protected:
	
		sf::Time _last_active;
		sf::Time _ready_time;

		sf::Time _ready_animation_time;
		sf::Time _last_animation_active;

		int _block_length;

		int _block_length_copy;

		int _distance_traveled;

		bool _is_moving;

	public:
		
		struct items
		{
			//here come items baby 
		};

		ActiveObiect();

		void setLastActive(sf::Clock currentTime);

		void setLastActiveAnimation(sf::Clock currentTime);

		sf::Time getLastActiveTime();

		sf::Time getReadyTime();

		int getBlockLenghtCopy();

		void resetBlockLenghtCopy();

		void decreaseBlockLengthCopy();

		void procedureMove();

		void setIsMoving(bool isTrue);

		bool getIsMoving();

		int getTraveledDistance();
	};
}
#endif