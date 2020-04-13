#pragma once

#include "Player.h"

namespace RTB
{
	void Player::_dealSwordDamage(std::list<std::shared_ptr<Character>>& list_of_bots)
	{
		for (std::list<std::shared_ptr<Character>>::iterator iterator = list_of_bots.begin();//Iterates through list of bots...
			iterator != list_of_bots.end(); iterator++)
		{
			if ((*iterator)->isAlive() && _sword_hitbox->checkIntersection((*iterator)->getHitbox().getGlobalBounds()) == true)//checks if sword intersected one of them...
			{
				(*iterator)->subtractHP(10);//and subtracts hp
			}
		}
		_movement->notReadyToDealSwordDamage();
	}

	void Player::_dealBowDamage(std::list<std::shared_ptr<Character>>& list_of_bots)//as above
	{
		for (std::list<std::shared_ptr<Character>>::iterator iterator = list_of_bots.begin();
			iterator != list_of_bots.end(); iterator++)
		{
			if ((*iterator)->isAlive() && _arrows->isFlying() && _arrows->checkIntersection((*iterator)->getHitbox().getGlobalBounds()) == true)
			{
				(*iterator)->subtractHP(1);
			}
		}
	}

	void Player::_isColidingWithTile(std::vector<std::vector<std::unique_ptr<MapElement>>>& map_objects)
	{
		sf::Vector2i character_position = { (int)(((2 * _character_sprite->getPosition().y + _character_sprite->getPosition().x) / 2) / 25), (int)(((2 * _character_sprite->getPosition().y - _character_sprite->getPosition().x) / 2) / 25) };
		unsigned int height = map_objects[0].size(), width = map_objects.size();

		if (character_position.y > height - 1 || character_position.x < 0 || character_position.x > width - 1 || character_position.y < 0)//checks if character is situated "inside" the map
		{
			if (_direction == up)
				_moving_up = false;

			else if (_direction == down)
				_moving_down = false;

			else if (_direction == right)
				_moving_right = false;

			else if (_direction == left)
				_moving_left = false;
		}
		else
		{
			short furthest_up = 0, furthest_down = 0, furthest_left = 0, furthest_right = 0, range = 3;
			//up
			short iterator_y = character_position.y;
			while (furthest_up < range && iterator_y > 0)
			{
				furthest_up++;
				iterator_y--;
			}
			//down
			iterator_y = character_position.y;
			while (furthest_down < range && iterator_y < height)
			{
				furthest_down++;
				iterator_y++;
			}
			//left
			short iterator_x = character_position.x;
			while (furthest_left < range && iterator_x > 0)
			{
				furthest_left++;
				iterator_x--;
			}
			//right
			iterator_x = character_position.x;
			while (furthest_right < range && iterator_x < width)
			{
				furthest_right++;
				iterator_x++;
			}
			int start_x = character_position.x - furthest_left;
			int end_x = character_position.x + furthest_right;
			int start_y = character_position.y - furthest_up;
			int end_y = character_position.y + furthest_down;
			for (unsigned int i = start_x; i < end_x; ++i)
			{
				for (unsigned int j = start_y; j < end_y; ++j)
				{
					if (checkMapCollision(map_objects[i][j]->getObjectsHitbox(), _hitbox->getRectangle()))
					{
						if (_direction == up)
							_moving_up = false;

						else if (_direction == down)
							_moving_down = false;

						else if (_direction == right)
							_moving_right = false;

						else if (_direction == left)
							_moving_left = false;
					}
				}
			}
		}
	}

	Player::Player(sf::Texture texture, short health_points, sf::Texture& arrow_texture)
	{
		_health_points = health_points;
		_character_sprite = new sf::Sprite;
		_movement = new RiD::Movement(texture, _character_sprite);
		_hitbox = new Hitbox(_character_sprite, { 24.f, 46.f }, { -12.f,-16.f });
		_sword_hitbox = new SwordHitbox(_character_sprite);
		_hp_bar = new HPBar(_character_sprite, _health_points);
		_arrows = new Arrow(_character_sprite, arrow_texture);
		_is_alive = true;
		_arrows_count = 10;
		_speed = 1.f;
	}

	Player::~Player()
	{
		delete _movement;
		delete _hitbox;
		delete _character_sprite;
		delete _hp_bar;
		delete _arrows;
		delete _sword_hitbox;
	}

	void Player::update(sf::Time time, std::vector<std::vector<std::unique_ptr<MapElement>>>& map_objects,
		std::list<std::shared_ptr<Character>>& list_of_bots)
	{
		_isColidingWithTile(map_objects);

		if (!_movement->isAttackTriggered() && !_movement->isShotTriggered())
		{
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && _moving_left == false) ||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && _moving_left == false)) return;
			else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && _moving_right == false) ||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && _moving_right == false)) return;
			else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && _moving_up == false) ||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && _moving_up == false)) return;
			else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && _moving_down == false) ||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && _moving_down == false)) return;
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && _moving_up)
				{
					_movement->walkingUp(time);
					_character_sprite->move(0.0f, -_speed);
				}


				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && _moving_down)
				{
					_movement->walkingDown(time);
					_character_sprite->move(0.0f, _speed);
				}


				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _moving_right)
				{
					_movement->walkingRight(time);
					_character_sprite->move(_speed, 0.0f);
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _moving_left)
				{
					_movement->walkingLeft(time);
					_character_sprite->move(-_speed, 0.0f);
				}

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			_movement->triggerAttack();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && _arrows->isFlying() == false)
			_movement->triggerShot();

		if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) &&
			(!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
			(_movement->isAttackTriggered() == false) && _movement->isShotTriggered() == false)
			_movement->idle(time);


		_hitbox->update();
		_hp_bar->update();
		_direction = _movement->getDirection();

		if (_movement->isDeathTriggered())
		{
			_movement->death(time);
			if (_movement->isDeathTriggered() == false)
				_is_alive = false;
		}
		_moving_up = _moving_down = _moving_right = _moving_left = true;
	}

	void Player::dealDamage(sf::Time time, std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderTarget& window)
	{
		//sword
		if (_movement->isAttackTriggered())
		{
			_movement->swordSwing(time);
			_sword_hitbox->update(_movement->getDirection());
			_sword_hitbox->render(window);
		}
		if (_movement->isReadyToDealSwordDamage())
			this->_dealSwordDamage(list_of_bots);

		//bow
		if (_movement->isShotTriggered())
		{
			_arrows_count--;
			_movement->bowShot(time);
			_arrows->update();
		}
		if (_movement->isReadyToShotArrow())
		{
			_arrows->fly(time, window, _direction);
			this->_dealBowDamage(list_of_bots);
		}

		if (_arrows->isFlying() == false)
			_movement->notReadyToShotArrow();
	}
}