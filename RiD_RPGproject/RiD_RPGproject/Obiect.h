#ifndef OBIECT_H
#define OBIECT_H

#include <SFML/Graphics.hpp>
#include "SpriteAnimation.h"

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

		SpriteAnimation aAnimation;

		Obiect();

		void setObiectCoord(int x, int y);

		void setObiectCoord( sf::Vector2f coord);

		 sf::Vector2f getObiectCoord();

		void setLastActiveAnimation(sf::Clock currentTime);
	};
}
#endif