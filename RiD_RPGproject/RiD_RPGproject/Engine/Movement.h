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
			sf::Time spear_animation_start_time;
			sf::Time spear_animation_frame_duration;
		};
	private:
		animationDuration animations;
		bool _is_attack_triggered, _is_shot_triggered, _is_death_triggered, _is_spear_triggered;
		short _row = 0, _xCord = 0, _yCord = 0, _direction = 0, _xAttackCord = 0,
			_yAttackCord = 0, _xshotCord = 0, _yShotCord = 0, _yDeathCord = 0, _xDeathCord = 0, _ySpearCord = 0, _xSpearCord = 0;
		enum directions { up, left, down, right };
		enum rowsInPNGFile { walkUpAnim = 8, walkLeftAnim, walkDownAnim, walkRightAnim, shotAnim = 16, deathAnim = 20, swordSwingAnim };
		sf::Texture _texture;
		sf::Sprite* _object;

		bool _ready_to_deal_sword_damage = false, _ready_to_shot_arrow = false, _ready_to_deal_spear_damage = false;
	public:
		Movement(sf::Texture texture, sf::Sprite*& object);

		void walkingUp(sf::Time time, float speed_x, float speed_y);

		void walkingDown(sf::Time time, float speed_x, float speed_y);

		void walkingLeft(sf::Time time, float speed_x, float speed_y);

		void walkingRight(sf::Time time, float speed_x, float speed_y);

		void swordSwing(sf::Time time);

		void spearPoke(sf::Time time);

		void bowShot(sf::Time time, short direction);

		void idle(sf::Time time);

		void dead();

		void death(sf::Time time);

		void triggerSpear();

		void triggerAttack();

		void triggerShot();

		void triggerDeath();

		bool isSpearTriggered();

		bool isAttackTriggered();

		bool isShotTriggered();

		bool isDeathTriggered();

		bool isReadyToDealSpearDamage();

		bool isReadyToDealSwordDamage();

		void notReadyToDealSpearDamage();

		void notReadyToDealSwordDamage();

		bool isReadyToShotArrow();

		void notReadyToShotArrow();

		//Returns sprite
		sf::Sprite getSprite();

		short getDirection();

		void setSpritePosition(sf::Vector2f position);
	};
}