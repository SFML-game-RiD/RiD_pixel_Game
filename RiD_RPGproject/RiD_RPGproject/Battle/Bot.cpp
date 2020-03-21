#pragma once

#include "Bot.h"

namespace RTB
{
	Bot::Bot(sf::Texture texture)
	{
		_character_sprite = new sf::Sprite;
		_movement = new RiD::Movement(texture, _character_sprite);
		_hitbox = new Hitbox(_character_sprite, { 32.f, 48.f }, { -17.f,-16.f });
		_hp_bar = new HPBar(_character_sprite);
		_is_alive = true;
		_health_points = 100;
	}

	Bot::~Bot()
	{
		delete _movement;
		delete _hitbox;
		delete _character_sprite;
		delete _hp_bar;
	}

	void Bot::setPosition(sf::Vector2f position)
	{
		_movement->setSpritePosition(position);
	}

	const void Bot::update(sf::Time time)
	{
		/*_movement->walkingUp(time);
		_movement->walkingDown(time);
		_movement->walkingRight(time);
		_movement->walkingLeft(time);
		*/

		_movement->idle(time);
		_hitbox->update();
		_hp_bar->update();
	}

	void Bot::render(sf::RenderWindow& window)
	{
		window.draw(_movement->getSprite());
		_hitbox->render(window);
		_hp_bar->render(window);
	}

	bool Bot::isAlive()
	{
		return _is_alive;
	}
}