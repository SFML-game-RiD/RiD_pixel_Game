#pragma once

#include "Animation.h"

namespace RiD
{
	Animation::Animation(sf::Sprite& sprite) :_animated_sprite(sprite), _p_texture(nullptr), _animation_length(0.0f), _animation_progression(0.0f) {}

	void Animation::addFrame(frame&& newFrame)
	{
		this->_animation_length += newFrame.duration;
		this->_frames.push_back(std::move(newFrame));
	}

	void Animation::setTexture(const sf::Texture &texture)
	{
		_p_texture = &texture;
	}

	unsigned int Animation::getFrameCount() const
	{
		return _frames.size();
	}

	void Animation::update(double time_passed)
	{
		_animation_progression += time_passed;
		double progress_tmp = this->_animation_progression;
		for (unsigned short i = 0; i < _frames.size(); i++)
		{
			progress_tmp -= _frames[i].duration;
			if (progress_tmp < 0.0f || &(_frames[i]) == &_frames.back())
			{
				_animated_sprite.setTextureRect(_frames[i].rectangle);
				break;
			}
		}
	}


}