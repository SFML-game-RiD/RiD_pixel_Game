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

	public:

		MapAnimation animationMaker;

		Obiect();

		void setObiectCoord(int x, int y);

		std::pair<int,int> getObiectCoord();

	};
}
#endif