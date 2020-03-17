#pragma once

#include "AssetManager.h"

namespace RiD
{
	class Movement
	{
	private:
		short _row = 0, _xCord = 0, _yCord = 0, _direction = 0;
		enum directions { up, left, down, right };
		enum rowsInPNGFile { walkUpAnim = 8, walkLeftAnim, walkDownAnim, walkRightAnim };
		sf::Texture _texture;
		sf::Sprite _object;
		sf::Time _animation_start_time;
		sf::Time _animation_frame_duration;
	public:
		Movement(sf::Texture texture);

		/*
		Walking animation with movement included
		@param starting_row row in *.png file where desired frames starts
		@param time
		*/
		void walking(short starting_row, sf::Time time);

		void walkingUp(sf::Time time);

		void walkingDown(sf::Time time);

		void walkingLeft(sf::Time time);

		void walkingRight(sf::Time time);

		/*
		Idle animation
		@param time
		*/
		void idle(sf::Time time);

		//Returns sprite
		sf::Sprite getSprite();
	};
}