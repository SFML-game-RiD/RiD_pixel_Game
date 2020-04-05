#pragma once

#include "Archer.h"

namespace RTB
{
	Archer::Archer(sf::Texture texture, short health_points, sf::Texture& arrow_texture)
	{
		_health_points = health_points;
		_character_sprite = new sf::Sprite;
		_movement = new RiD::Movement(texture, _character_sprite);
		_hitbox = new Hitbox(_character_sprite, { 24.f, 46.f }, { -12.f,-16.f });
		_hp_bar = new HPBar(_character_sprite, _health_points);
		_arrows = new Arrow(_character_sprite, arrow_texture);
		_is_alive = true;
	}

	Archer::~Archer()
	{
		delete _movement;
		delete _hitbox;
		delete _character_sprite;
		delete _hp_bar;
		delete _arrows;
	}
	void Archer::update(sf::Time time, std::vector<std::vector<_obj>>& map_objects)
	{
	}
	void Archer::dealDamage(sf::Time time, std::list<Character*>& list_of_bots, sf::RenderTarget& window)
	{
	}
}