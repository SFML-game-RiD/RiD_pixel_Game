#pragma once

#include "AssetManager.h"

namespace RiD
{
	class Movement
	{
		struct animationDuration
		{
			sf::Time walking_animation_start_time;
			sf::Time walking_animation_frame_duration;
			sf::Time sword_animation_start_time;
			sf::Time sword_animation_frame_duration;
		};
	private:
		animationDuration animations;
		bool _is_attack_triggered;
		short _row = 0, _xCord = 0, _yCord = 0, _direction = 0, _xAttackCord = 0, _yAttackCord = 0;
		enum directions { up, left, down, right };
		enum rowsInPNGFile { walkUpAnim = 8, walkLeftAnim, walkDownAnim, walkRightAnim, swordSwingAnim=21 };
		sf::Texture _texture;
		sf::Sprite _object;
	public:
		Movement(sf::Texture texture);

		void walkingUp(sf::Time time);

		void walkingDown(sf::Time time);

		void walkingLeft(sf::Time time);

		void walkingRight(sf::Time time);

		void swordSwing(sf::Time time);

		void idle(sf::Time time);

		void triggerAttack();

		bool isAttackTriggered();

		//Returns sprite
		sf::Sprite getSprite();
	};
}