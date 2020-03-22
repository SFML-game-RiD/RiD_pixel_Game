#ifndef _ACTIVEOBIECT_H_
#define _ACTIVEOBIECT_H_

#include "Obiect.h"

namespace MP
{
	class ActiveObiect :public Obiect
	{
	private:
	
		sf::Time _last_active;

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

		int getBlockLenghtCopy();

		void resetBlockLenghtCopy();

		void decreaseBlockLengthCopy();

		void procedureMove();

		void setIsMoving(bool isTrue);

		bool getIsMoving();
	};
}
#endif