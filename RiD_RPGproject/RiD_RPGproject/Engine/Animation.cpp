#pragma once

#include "Animation.h"

namespace RiD
{
	Animation::Animation(sf::IntRect start_rectangle, double width, double end, sf::Time frame_duration, sf::Texture texture) :
		_frame_start(sf::Time::Zero), _width(width), _end(end), _frame_duration(frame_duration), _rectangle(start_rectangle), _texture(texture)
	{
		_object.setTexture(_texture);
		_object.setTextureRect(_rectangle);
	}


	void Animation::updateAnimation(sf::Time time)
	{
		if (time.asSeconds() - _frame_start.asSeconds() >= _frame_duration.asSeconds()) {
			if (_rectangle.left == _end)
				_rectangle.left = 0;
			else
				_rectangle.left += _width;

			_object.setTextureRect(_rectangle);
			_frame_start = time;
		}
	}

	const sf::Sprite& Animation::getObjectSprite()
	{
		return this->_object;
	}

}