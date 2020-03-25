#pragma once

#include "Movement.h"

namespace RiD
{
	Movement::Movement(sf::Texture texture, sf::Sprite*& object) : _texture(texture),
		animations{ sf::Time::Zero, sf::seconds(1.f / 12.f), sf::Time::Zero, sf::seconds(1.f / 12.f),
		sf::Time::Zero, sf::seconds(1.f/12.f),sf::Time::Zero, sf::seconds(1.f / 8.f) },
		_is_attack_triggered(false), _is_shot_triggered(false), _is_death_triggered(false), _object(object)
	{
		_object->setTexture(_texture);
		_xCord = 1;
		_xAttackCord = 1;
		_xshotCord = 1;
		_xDeathCord = 1;
		_direction = down;
	}

	void Movement::walkingUp(sf::Time time)
	{
		if (!_is_attack_triggered && !_is_shot_triggered && !_is_death_triggered)
		{
			_yCord = walkUpAnim;
			_object->setOrigin(32.0, 32.0);
			_object->setTextureRect(sf::IntRect(_xCord * 64, _yCord * 64, 64, 64));
			_object->move(0.0f, -1.0f);
			_direction = up;

			if (_xCord * 64 >= 576)
				_xCord = 0;

			if (time - animations.walking_animation_start_time >= animations.walking_animation_frame_duration)
			{
				_xCord++;
				animations.walking_animation_start_time = time;

				if (_xCord * 64 >= 576)
					_xCord = 0;
			}
		}
	}

	void Movement::walkingDown(sf::Time time)
	{
		if (!_is_attack_triggered && !_is_shot_triggered && !_is_death_triggered)
		{
			_yCord = walkDownAnim;
			_object->setOrigin(32.0, 32.0);
			_object->setTextureRect(sf::IntRect(_xCord * 64, _yCord * 64, 64, 64));
			_object->move(0.0f, 1.0f);
			_direction = down;

			if (time - animations.walking_animation_start_time >= animations.walking_animation_frame_duration)
			{
				_xCord++;
				animations.walking_animation_start_time = time;

				if (_xCord * 64 >= 576)
					_xCord = 0;
			}
		}
	}

	void Movement::walkingLeft(sf::Time time)
	{
		if (!_is_attack_triggered && !_is_shot_triggered && !_is_death_triggered)
		{
			_yCord = walkLeftAnim;
			_object->setOrigin(32.0, 32.0);
			_object->setTextureRect(sf::IntRect(_xCord * 64, _yCord * 64, 64, 64));
			_object->move(-1.0f, 0.0f);
			_direction = left;

			if (time - animations.walking_animation_start_time >= animations.walking_animation_frame_duration)
			{
				_xCord++;
				animations.walking_animation_start_time = time;

				if (_xCord * 64 >= 576)
					_xCord = 0;
			}
		}
	}

	void Movement::walkingRight(sf::Time time)
	{
		if (!_is_attack_triggered && !_is_shot_triggered && !_is_death_triggered)
		{
			_yCord = walkRightAnim;
			_object->setOrigin(32.0, 32.0);
			_object->setTextureRect(sf::IntRect(_xCord * 64, _yCord * 64, 64, 64));
			_object->move(1.0f, 0.0f);
			_direction = right;

			if (time - animations.walking_animation_start_time >= animations.walking_animation_frame_duration)
			{
				_xCord++;
				animations.walking_animation_start_time = time;

				if (_xCord * 64 >= 576)
					_xCord = 0;
			}
		}
	}

	void Movement::swordSwing(sf::Time time)
	{
		//if (_is_attack_triggered)
		//{
			_yAttackCord = swordSwingAnim * 64;
			_object->setOrigin(96.0, 96.0);
			_object->setTextureRect(sf::IntRect(_xAttackCord * 192, _yAttackCord + (_direction * 192), 192, 192));

			
			if (time - animations.sword_animation_start_time >= animations.sword_animation_frame_duration)
			{
				_xAttackCord++;
				animations.sword_animation_start_time = time;
				if (_xAttackCord * 192 == 1152)
				{
					_is_attack_triggered = false;
					_ready_to_deal_sword_damage = true;
					_xAttackCord = 0;
				}
			}
	//	}
	}

	void Movement::bowShot(sf::Time time)
	{
		//if (_is_shot_triggered)
		//{
			_yShotCord = shotAnim *64;
			_object->setOrigin(32.0, 32.0);
			_object->setTextureRect(sf::IntRect(_xshotCord * 64, _yShotCord + (_direction * 64), 64, 64));

			if (time - animations.bow_shot_animation_start_time >= animations.bow_shot_animation_frame_duration)
			{
				_xshotCord++;
				animations.bow_shot_animation_start_time = time;
				if (_xshotCord * 64 == 768)
				{
					_is_shot_triggered = false;
					_ready_to_shot_arrow = true;
					_xshotCord = 0;
				}
			}
		//}
	}

	void Movement::idle(sf::Time time)
	{
		_object->setOrigin(32.0, 32.0);
		_object->setTextureRect(sf::IntRect(1, 64 * _direction, 64, 64));
	}

	void Movement::death(sf::Time time)
	{
		if (_is_death_triggered)
		{
			_yDeathCord = deathAnim;
			_object->setOrigin(32.0, 32.0);
			_object->setTextureRect(sf::IntRect(_xDeathCord * 64, _yDeathCord * 64, 64, 64));

			if (time - animations.death_animation_start_time >= animations.death_animation_frame_duration)
			{
				_xDeathCord++;
				animations.death_animation_start_time = time;
				if (_xDeathCord * 64 == 384)
				{
					_is_death_triggered = false;
					_xDeathCord = 0;
				}
			}
		}
	}

	void Movement::triggerAttack()
	{
		_is_attack_triggered = true;
	}

	void Movement::triggerShot()
	{
		_is_shot_triggered = true;
	}

	void Movement::triggerDeath()
	{
		_is_death_triggered = true;
	}

	bool Movement::isAttackTriggered()
	{
		return _is_attack_triggered;
	}

	bool Movement::isShotTriggered()
	{
		return _is_shot_triggered;
	}

	bool Movement::isDeathTriggered()
	{
		return _is_death_triggered;
	}

	bool Movement::isReadyToDealSwordDamage()
	{
		return _ready_to_deal_sword_damage;
	}

	void Movement::notReadyToDealSwordDamage()
	{
		_ready_to_deal_sword_damage = false;
	}

	bool Movement::isReadyToShotArrow()
	{
		return _ready_to_shot_arrow;
	}

	void Movement::notReadyToShotArrow()
	{
		_ready_to_shot_arrow = false;
	}

	sf::Sprite Movement::getSprite()
	{
		return *_object;
	}

	short Movement::getDirection()
	{
		return _direction;
	}

	void Movement::setSpritePosition(sf::Vector2f position)
	{
		_object->setPosition(position);
	}
}