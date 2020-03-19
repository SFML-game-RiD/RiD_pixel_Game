#pragma once

#include "Player.h"

namespace RTB
{
	Player::Player(sf::Texture texture)
	{
		_character_sprite = new sf::Sprite;
		_movement = new RiD::Movement(texture, _character_sprite);
		_hitbox = new Hitbox(_character_sprite, { 32.f, 48.f }, { -17.f,-16.f });
		_hp_bar = new HPBar(_character_sprite);
		_is_alive = true;
		_health_points = 100;
	}

	Player::~Player()
	{
		delete _movement;
		delete _hitbox;
		delete _character_sprite;
		delete _hp_bar;
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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			_movement->triggerShot();

		if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) &&
			(!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
			(_movement->isAttackTriggered() == false) && _movement->isShotTriggered() == false)
			_movement->idle(time);

		_movement->swordSwing(time);
		_movement->bowShot(time);
		_hitbox->update();
		_hp_bar->update();
		if (_is_alive == false)
		{
			_movement->death(time);
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
}