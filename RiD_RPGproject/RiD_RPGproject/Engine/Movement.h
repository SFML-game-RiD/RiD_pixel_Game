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
			sf::Time bow_shot_animation_start_time;
			sf::Time bow_shot_animation_frame_duration;
			sf::Time death_animation_start_time;
			sf::Time death_animation_frame_duration;
		};
	private:
		animationDuration animations;
		bool _is_attack_triggered, _is_shot_triggered, _is_death_triggered;
		short _row = 0, _xCord = 0, _yCord = 0, _direction = 0, _xAttackCord = 0,
			_yAttackCord = 0, _xshotCord = 0, _yShotCord = 0, _yDeathCord = 0, _xDeathCord = 0;
		enum directions { up, left, down, right };
		enum rowsInPNGFile { walkUpAnim = 8, walkLeftAnim, walkDownAnim, walkRightAnim, shotAnim = 16, deathAnim = 20, swordSwingAnim };
		sf::Texture _texture;
		sf::Sprite *_object;

		bool _ready_to_deal_sword_damage = false;
	public:
		Movement(sf::Texture texture, sf::Sprite *&object);

		void walkingUp(sf::Time time);

		void walkingDown(sf::Time time);

		void walkingLeft(sf::Time time);

		void walkingRight(sf::Time time);

		void swordSwing(sf::Time time);

		void bowShot(sf::Time time);

		void idle(sf::Time time);

		void death(sf::Time time);

		void triggerAttack();

		void triggerShot();

		void triggerDeath();

		bool isAttackTriggered();

		bool isShotTriggered();

		bool isDeathTriggered();

		bool isReadyToDealSwordDamage();

		void notReadyToDealSwordDamage();

		//Returns sprite
		sf::Sprite getSprite();

		short getDirection();

		void setSpritePosition(sf::Vector2f position);
	};
}