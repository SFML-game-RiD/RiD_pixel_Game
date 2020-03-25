#pragma once

#include "Arrow.h"

namespace RTB
{
	Arrow::Arrow(sf::Sprite*& character, sf::Texture& texture) : _character(character), _is_flying(false), _change_direction(true),
		_fly_time(sf::seconds(0.5)), _start_time(sf::Time::Zero)
	{
		_sprite.setTexture(texture);
		_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		_sprite.setPosition(character->getPosition());
	}

	void Arrow::update()
	{
		_sprite.setPosition(_character->getPosition().x + 2.f, _character->getPosition().y);
	}

	void Arrow::render(sf::RenderTarget& window)
	{
		window.draw(_sprite);
	}

	void Arrow::fly(sf::Time time, sf::RenderTarget& window, short direction)
	{
		if (_change_direction == true)
		{
			_is_flying = true;
			_direction = direction;
			_change_direction = false;
			_start_time = time;
		}

		if (_direction == right)
		{
			if (time - _start_time < _fly_time)
			{
				_sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
				_sprite.setOrigin(16.f, 16.f);
				_sprite.move(_speed, 0.0f);
				window.draw(_sprite);
			}
			else
			{
				_is_flying = false;
				_change_direction = true;
			}
				
		}
		else if (_direction == left)
		{
			if (time - _start_time < _fly_time)
			{
				_sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
				_sprite.setOrigin(16.f, 16.f);
				_sprite.move(-_speed, 0.0f);
				window.draw(_sprite);
			}
			else
			{
				_is_flying = false;
				_change_direction = true;
			}
		}
		else if (_direction == up)
		{
			if (time - _start_time < _fly_time)
			{
				_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
				_sprite.setOrigin(16.f, 16.f);
				_sprite.move(0.0f, -_speed);
				window.draw(_sprite);
			}
			else
			{
				_is_flying = false;
				_change_direction = true;
			}
		}
		else if (_direction == down)
		{
			if (time - _start_time < _fly_time)
			{
				_sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
				_sprite.setOrigin(16.f, 16.f);
				_sprite.move(0.0f, _speed);
				window.draw(_sprite);
			}
			else
			{
				_is_flying = false;
				_change_direction = true;
			}
		}

	}

	bool Arrow::isFlying()
	{
		return _is_flying;
	}
}