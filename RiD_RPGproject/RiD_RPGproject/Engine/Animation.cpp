#pragma once

#include "Animation.h"

namespace RiD
{
	Animation::Animation(sf::IntRect start_rectangle, short width, short number_of_frames, sf::Time frame_duration, sf::Texture texture, short playback_mode) :
		_frame_start(sf::Time::Zero), _width(width), _number_of_frames(number_of_frames), _frame_duration(frame_duration), _rectangle(start_rectangle), _texture(texture), _playback_mode(playback_mode), _is_triggered(false)
	{
		_object.setTexture(_texture);
		_object.setTextureRect(_rectangle);
		_end = (_number_of_frames-1) * width;
	}


	void Animation::updateAnimation(sf::Time time)
	{
		if (time.asSeconds() - _frame_start.asSeconds() >= _frame_duration.asSeconds() && _is_triggered == true) {
			if (_rectangle.left == _end && _playback_mode == loop)
				_rectangle.left = 0;
			else if (_rectangle.left == _end && _playback_mode == single)
			{
				_rectangle.left = 0;
				_object.setTextureRect(_rectangle);
				_is_triggered = false;
				return;
			}
			else
				_rectangle.left += _width;

			_object.setTextureRect(_rectangle);
			_frame_start = time;
		}
	}

	sf::Sprite Animation::getObjectSprite()
	{
		return this->_object;
	}

	void Animation::triggerAnimation()
	{
		_is_triggered = true;
	}

	void Animation::stopLoopedAnimation()
	{
		_rectangle.left = 0;
		_object.setTextureRect(_rectangle);
		_is_triggered = false;
	}

}