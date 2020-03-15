#pragma once

#include "SFML/Graphics.hpp"
#include "AssetManager.h"

namespace RiD
{
	class Animation
	{
	private:
		bool _is_triggered;
		short _number_of_frames, _playback_mode, _width, _end;
		sf::Time _frame_start, _frame_duration;
		sf::Sprite _object;
		sf::IntRect _rectangle;
		sf::Texture _texture;
	public:
		enum playbackMode { loop, single };
		/*
		@param start_rectangle starting rect
		@param width width of the frame
		@param number_of_frames 
		@param frame_duration frame duration
		@param texture
		@param playback_mode loop or single
		*/
		Animation(sf::IntRect start_rectangle, short width, short number_of_frames, sf::Time frame_duration, sf::Texture texture, short playback_mode);
		Animation();
		/*
		Updates animation
		@param time elapsed time
		*/
		void updateAnimation(sf::Time time);

		//Returns sprite ready to be drawn
		sf::Sprite getObjectSprite();

		//Starts both types of animations
		void triggerAnimation();

		//Stops looped animation
		void stopLoopedAnimation();

		//Sets all parameters needed to create animation
		void setParameters(sf::IntRect start_rectangle, short width, short number_of_frames, sf::Time frame_duration, sf::Texture texture, short playback_mode);

		//Sets position on the map
		void setSpritePosition(sf::Vector2f position);

		//Moves sprite to the new position
		void moveSprite(sf::Vector2f new_position);
	};
}