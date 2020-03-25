#ifndef _ACTIVEOBIECT_H_
#define _ACTIVEOBIECT_H_

#include "Obiect.h"

namespace MP
{
	class ActiveObiect :public Obiect
	{
	protected:
	
		//Responsible for moving
		sf::Time _last_active;/// Last time, when obiect was moving.
		sf::Time _ready_time;/// Calculated time, when obiect is able to move.
		sf::Time active_obj_sleep_time;
		sf::Time active_obj_animation_sleep_time;

		int _block_length;//<<<< This variable should be downloaded from classes responsible for map !
		int _block_length_copy;
		int _distance_traveled;
		int _velocity; /// Ammount of pixel active_obj_animation_sleep_time

	public:

		ActiveObiect();

		void setLastActive(sf::Clock currentTime);

		void setLastActiveAnimation(sf::Clock currentTime);

		sf::Time getLastActiveTime();

		sf::Time getReadyTime();

		int getBlockLenghtCopy();

		int getTraveledDistance();
		
		int getVelocity();

		void resetBlockLenghtCopy();

		void decreaseBlockLengthCopy();

		void procedureMove();
	};
}
#endif