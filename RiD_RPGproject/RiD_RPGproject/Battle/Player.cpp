#pragma once

#include "Player.h"
#include <iostream>
namespace RTB
{
	void Player::_dealSwordDamage(std::list<Bot*>& list_of_bots)
	{
		for (std::list<Bot*>::iterator iterator = list_of_bots.begin();//Iterates through list of bots...
			iterator != list_of_bots.end(); iterator++)
		{
			if (_sword_hitbox->checkIntersection((*iterator)->getHitbox().getGlobalBounds()) == true)//checks if sword intersected one of them...
			{
				(*iterator)->subtractHP(10);//and subtracts hp
			}
		}
		_movement->notReadyToDealSwordDamage();
	}

	void Player::_dealBowDamage(std::list<Bot*>& list_of_bots)//as above
	{
		for (std::list<Bot*>::iterator iterator = list_of_bots.begin();
			iterator != list_of_bots.end(); iterator++)
		{
			if (_arrows->isFlying() && _arrows->checkIntersection((*iterator)->getHitbox().getGlobalBounds()) == true)
			{
				(*iterator)->subtractHP(1);
			}
		}
	}

	void Player::_isColidingWithTile(std::vector<std::vector<_obj>>& map_objects)
	{
		std::vector< std::vector<_obj> >::iterator row;
		std::vector<_obj>::iterator col;
		for (row = map_objects.begin(); row != map_objects.end(); row++) {
			for (col = row->begin(); col != row->end(); col++) {
				if (checkMapCollision(col->hitbox,_hitbox->getRectangle()))
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

	void Player::setPosition(sf::Vector2f position)
	{
		_movement->setSpritePosition(position);
	}

	void Player::update(sf::Time time, std::vector<std::vector<_obj>>& map_objects)
	{
		_isColidingWithTile(map_objects);
		

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
				_movement->walkingUp(time);

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && _moving_down)
				_movement->walkingDown(time);

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _moving_right)
				_movement->walkingRight(time);

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _moving_left)
				_movement->walkingLeft(time);
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

	void Player::render(sf::RenderWindow& window)
	{
		window.draw(_movement->getSprite());
		_hitbox->render(window);
		_hp_bar->render(window);
	}

	bool Player::isAlive()
	{
		return _is_alive;
	}

	sf::Vector2f Player::getPosition()
	{
		return _movement->getSprite().getPosition();
	}

	void Player::dealDamage(sf::Time time, std::list<Bot*>& list_of_bots, sf::RenderTarget& window)
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
	bool Player::checkMapCollision(const sf::RectangleShape& Object1, const sf::RectangleShape& Object2)
	{
		OrientedHitbox OH1(Object1, Object1.getSize().x, Object1.getSize().y);
		OrientedHitbox OH2(Object2, Object2.getSize().x, Object2.getSize().y);

		// Create the four distinct axes that are perpendicular to the edges of the two rectangles
		sf::Vector2f Axes[4] = {
			sf::Vector2f(OH1.Points[1].x - OH1.Points[0].x,
			OH1.Points[1].y - OH1.Points[0].y),
			sf::Vector2f(OH1.Points[1].x - OH1.Points[2].x,
			OH1.Points[1].y - OH1.Points[2].y),
			sf::Vector2f(OH2.Points[0].x - OH2.Points[3].x,
			OH2.Points[0].y - OH2.Points[3].y),
			sf::Vector2f(OH2.Points[0].x - OH2.Points[1].x,
			OH2.Points[0].y - OH2.Points[1].y)
		};

		for (int i = 0; i < 4; i++) // For each axis...
		{
			float MinOH1, MaxOH1, MinOH2, MaxOH2;

			// ... project the points of both OBBs onto the axis ...
			OH1.ProjectOntoAxis(Axes[i], MinOH1, MaxOH1);
			OH2.ProjectOntoAxis(Axes[i], MinOH2, MaxOH2);

			// ... and check whether the outermost projected points of both OBBs overlap.
			// If this is not the case, the Separating Axis Theorem states that there can be no collision between the rectangles
			if (!((MinOH2 <= MaxOH1) && (MaxOH2 >= MinOH1)))
				return false;
		}
		return true;
	}
}