#pragma once

#include "Swordsman.h"

namespace RTB
{
	Swordsman::Swordsman(sf::Texture texture, short health_points)
	{
		_health_points = health_points;
		_character_sprite = new sf::Sprite;
		_movement = new RiD::Movement(texture, _character_sprite);
		_hitbox = new Hitbox(_character_sprite, { 24.f, 46.f }, { -12.f,-16.f });
		_sword_hitbox = new SwordHitbox(_character_sprite);
		_hp_bar = new HPBar(_character_sprite, _health_points);
		_is_alive = true;
	}

	Swordsman::~Swordsman()
	{
		delete _movement;
		delete _hitbox;
		delete _character_sprite;
		delete _hp_bar;
		delete _sword_hitbox;
	}

	void Swordsman::setPosition(sf::Vector2f position)
	{
		_movement->setSpritePosition(position);
	}

	void Swordsman::update(sf::Time time, std::vector<std::vector<std::unique_ptr<MapElement>>>& map_objects)
	{
		/*_movement->walkingUp(time);
		_movement->walkingDown(time);
		_movement->walkingRight(time);
		_movement->walkingLeft(time);
		*/
		_movement->idle(time);
		_hitbox->update();
		_hp_bar->update();
		if (_movement->isDeathTriggered())
		{
			_movement->death(time);
			if(_movement->isDeathTriggered()==false)
				_is_alive = false;
		}
	}

	void Swordsman::render(sf::RenderWindow& window)
	{
		window.draw(_movement->getSprite());
		_hitbox->render(window);
		_hp_bar->render(window);
	}

	bool Swordsman::isAlive()
	{
		return _is_alive;
	}
	sf::Vector2f Swordsman::getPosition()
	{
		return _movement->getSprite().getPosition();
	}

	sf::RectangleShape Swordsman::getHitbox()
	{
		return _hitbox->getRectangle();
	}

	void Swordsman::dealDamage(sf::Time time, std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderTarget& window)
	{
	}

	void Swordsman::subtractHP(short value)
	{
		_health_points -= value;
		_hp_bar->shortenBar(value);
		if (_health_points < 1)
		{
			_movement->triggerDeath();
		}

	}
}