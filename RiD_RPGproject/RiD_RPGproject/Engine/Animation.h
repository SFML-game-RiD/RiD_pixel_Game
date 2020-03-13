#pragma once

#include <vector>
#include "SFML/Graphics/Texture.hpp"
#include "AssetManager.h"

namespace RiD
{
	class Animation
	{
	private:
		std::vector<frame> _frames;
		const sf::Texture* _p_texture;
		double _animation_length;
		double _animation_progression;
		sf::Sprite &_animated_sprite;
	public:
		Animation(sf::Sprite &sprite);
		/*
		Adds frame to the vector
		@param newFrame
		*/
		void addFrame(frame &&newFrame);
		//Sets texture
		void setTexture(const sf::Texture &texture);
		//Gets number of frames in vector
		unsigned int getFrameCount() const;
		/*
		Uptades animation
		@param time elapsed time
		*/
		void update(double time_passed);
	};
}