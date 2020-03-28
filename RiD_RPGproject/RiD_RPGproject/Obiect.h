#ifndef _OBIECT_H_
#define _OBIECT_H_

#include <utility>
#include <SFML/Graphics.hpp>
#include "MapAnimation.h"

namespace MP
{
	class Obiect
	{
	private:

		std::pair<int, int> _objCoord;

	protected:

		sf::Time _ready_animation_time;
		sf::Time _last_animation_active;
		sf::Time obj_animation_sleep_time;

	public:

		MapAnimation animationMaker;

		Obiect();

		void setObiectCoord(int x, int y);

		void setObiectCoord(std::pair<int,int> coord);

		std::pair<int,int> getObiectCoord();

		void setLastActiveAnimation(sf::Clock currentTime);
	};
}
#endif