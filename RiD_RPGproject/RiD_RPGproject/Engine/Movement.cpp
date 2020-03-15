#pragma once

#include "Movement.h"

namespace RiD
{
	Movement::Movement(sf::Texture texture): _texture(texture), _animation_start_time(sf::Time::Zero), _animation_frame_duration(sf::seconds(1.f / 12.f))
	{
		_object.setTexture(_texture);
		_xCord = 1;
		_direction = down;
		_object.setPosition(120.0, 120.0);
	}

	void Movement::walking(short starting_row, sf::Time time)
	{
		_yCord = starting_row;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			_yCord = starting_row;
			_object.setOrigin(32.0, 32.0);
			_object.setTextureRect(sf::IntRect(_xCord* 64, _yCord * 64, 64, 64));
			_object.move(0.0f, -1.0f);
			_direction = up;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			_yCord = starting_row + 1;
			_object.setOrigin(32.0, 32.0);
			_object.setTextureRect(sf::IntRect(_xCord * 64, _yCord * 64, 64, 64));
			_object.move(-1.0f, 0.0f);
			_direction = left;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			_yCord = starting_row + 2;
			_object.setOrigin(32.0, 32.0);
			_object.setTextureRect(sf::IntRect(_xCord * 64, _yCord * 64, 64, 64));
			_object.move(0.0f, 1.0f);
			_direction = down;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			_yCord = starting_row + 3;
			_object.setOrigin(32.0, 32.0);
			_object.setTextureRect(sf::IntRect(_xCord * 64, _yCord * 64, 64, 64));
			_object.move(1.0f, 0.0f);
			_direction = right;
		}

		if (_xCord * 64 >= 576)
			_xCord = 0;

		if (time - _animation_start_time >= _animation_frame_duration)
		{
			_xCord++;
			_animation_start_time = time;

			if (_xCord * 64 >= 576)
				_xCord = 0;
		}
	}
	void Movement::idle(sf::Time time)
	{
		if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
		{
			_object.setOrigin(32.0, 32.0);
			_object.setTextureRect(sf::IntRect(1, 64 * _direction, 64, 64));
		}
	}
	sf::Sprite Movement::getSprite()
	{
		return _object;
	}
}