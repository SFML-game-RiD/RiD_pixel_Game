#ifndef _PAWNOBIECT_H_
#define _PAWNOBIECT_H_

#include "ActiveObiect.h"

namespace MP 
{
	class PawnObiect:public ActiveObiect
	{
	private:

		enum direction 
		{
			directionUp,
			directionDown,
			directionLeft,
			directionRight,
			directionNone
		};

		direction _current_direction;
		int _past_pixel;
		bool _is_moving;
		int _travel_time;

	public:
		
		void setTravelTime(int travelTimeInMs);
	};
}
#endif
