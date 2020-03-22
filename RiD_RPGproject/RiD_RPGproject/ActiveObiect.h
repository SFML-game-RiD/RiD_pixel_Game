#ifndef _ACTIVEOBIECT_H_
#define _ACTIVEOBIECT_H_

#include "Obiect.h"

namespace MP
{
	class ActiveObiect :public Obiect
	{
	private:
	
		sf::Time _last_active;

		sf::Time _ready_time;

		int _block_length;

		int _block_length_copy;

		bool _is_moving;

	public:
		
		struct items
		{
			//here come items baby 
		};

		ActiveObiect();

		void setLastActive(sf::Clock currentTime);

		sf::Time getLastActiveTime();

		sf::Time getReadyTime();

		int getBlockLenghtCopy();

		void resetBlockLenghtCopy();

		void decreaseBlockLengthCopy();

		void procedureMove();

		void setIsMoving(bool isTrue);

		bool getIsMoving();
	};
}
#endif