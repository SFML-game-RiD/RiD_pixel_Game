#pragma once

#include "Player.h"
#include <iostream>
namespace RTB
{
	void Player::_dealSwordDamage(std::list<Bot*>& list_of_bots)
	{
		for (std::list<Bot*>::iterator iterator = list_of_bots.begin();
			iterator != list_of_bots.end(); iterator++)
		{
			if (_sword_hitbox->checkIntersection((*iterator)->getHitbox().getGlobalBounds()) == true)
			{
				(*iterator)->subtractHP(10);
			}
		}
		_movement->notReadyToDealSwordDamage();
	}

	Player::Player(sf::Texture texture, short health_points, sf::Texture& arrow_texture)
	{
		_health_points = health_points;
		_character_sprite = new sf::Sprite;
		_movement = new RiD::Movement(texture, _character_sprite);
		_hitbox = new Hitbox(_character_sprite, { 32.f, 48.f }, { -17.f,-16.f });
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

	void Player::update(sf::Time time)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			_movement->walkingUp(time);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			_movement->walkingDown(time);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			_movement->walkingRight(time);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			_movement->walkingLeft(time);

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
		if (_movement->isAttackTriggered())
		{
			_movement->swordSwing(time);
			_sword_hitbox->update(_movement->getDirection());
			_sword_hitbox->render(window);
		}
		if (_movement->isReadyToDealSwordDamage())
			this->_dealSwordDamage(list_of_bots);

		if (_movement->isShotTriggered())
		{
			_movement->bowShot(time);
			_arrows->update();
		}	
		if (_movement->isReadyToShotArrow())
			_arrows->fly(time, window, _direction);
		if (_arrows->isFlying() == false)
			_movement->notReadyToShotArrow();
	}
}