#pragma once

#include "SFML/Graphics.hpp"
#include "AssetManager.h"

namespace RiD
{
	class Animation
	{
	private:
		double _width, _end;
		sf::Time _frame_start, _frame_duration;
		sf::Sprite _object;
		sf::IntRect _rectangle;
		sf::Texture _texture;
	public:
		/*
		@param start_rectangle starting rect
		@param width width of the frame
		@param end end of the frame
		@param frame_duration frame duration
		*/
		Animation(sf::IntRect start_rectangle, double width, double end, sf::Time frame_duration, sf::Texture texture);

		/*
		Updates animation
		@param time elapsed time
		*/
		void updateAnimation(sf::Time time);

		//Returns sprite ready to be drawn
		sf::Sprite getObjectSprite();
	};
}