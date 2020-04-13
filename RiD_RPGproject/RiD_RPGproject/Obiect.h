#ifndef _OBIECT_H_
#define _OBIECT_H_

#include <SFML/Graphics.hpp>
#include "Animation.h"

namespace MP
{
	class Obiect
	{
	private:

		sf::Vector2f _objCoord;

	protected:

		sf::Time _ready_animation_time;

		sf::Time _last_animation_active;

		sf::Time _obj_animation_sleep_time;

	public:

		Animation aAnimation;

		Obiect();

		void setObiectCoord(int x, int y);

		void setObiectCoord( sf::Vector2f coord);

		 sf::Vector2f getObiectCoord();

		void setLastActiveAnimation(sf::Clock currentTime);
	};
}
#endif