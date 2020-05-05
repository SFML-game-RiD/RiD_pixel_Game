#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SpriteAnimation.h"

namespace MP
{
	class Object
	{
	private:

		sf::Vector2f _objCoord;///Stores object coord.



	protected:

		sf::Time _ready_animation_time;///Ammount of time when object will change his sprite.

		sf::Time _last_animation_active;///Last time when object changed sprite.

		sf::Time _obj_animation_sleep_time;///Ammount of time when object dont' change his sprite.

	public:

		SpriteAnimation aAnimation;///Manage animations.

		//Object constructor.
		Object();

		//Sets object coordinates.
		//@param x the x coordinates.
		//@param y the y coordinates.
		void setObjectCoord(int x, int y);

		//Sets object coordinates.
		//@param coord it contain coordinates x and y.
		void setObjectCoord( sf::Vector2f coord);

		//Returns object coord.
		//@return object coord.
		 sf::Vector2f getObjectCoord();

		//Sets time, when object changed spirte.
		//@param currentTime current time in game.
		void setLastActiveAnimation(sf::Clock currentTime);
	};
}