#pragma once

#include "Player.h"

namespace RTB
{
	Player::Player(RiD::Movement &movement): _movement(movement)
	{
	}

	void Player::setPosition(float x, float y)
	{
		_movement.setSpritePosition(x, y);
	}

	void Player::movement(sf::Time time)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			_movement.walkingUp(time);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				_movement.walkingDown(time);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				_movement.walkingRight(time);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				_movement.walkingLeft(time);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				_movement.triggerAttack();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				_movement.triggerShot();

			if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) &&
				(!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
				(_movement.isAttackTriggered() == false) && _movement.isShotTriggered() == false)
				_movement.idle(time);

			_movement.swordSwing(time);
			_movement.bowShot(time);
	}

	void Player::render(sf::RenderWindow& window)
	{
		window.draw(_movement.getSprite());
	}

	sf::Vector2f Player::getPosition()
	{
		return _movement.getSprite().getPosition();
	}
}