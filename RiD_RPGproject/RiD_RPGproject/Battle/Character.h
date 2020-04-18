#pragma once

#include <iostream>
#include <random>
#include <chrono>
#include <list>
#include "../Engine/Movement.h"
#include "Hitbox.h"
#include "HPBar.h"
#include "SwordHitbox.h"
#include "SpearHitbox.h"
#include "Arrow.h"
#include "../Map/TileMap.h"
#include "OrientedHitbox.h"

namespace RTB
{
	class Character
	{
	protected:
		sf::Sprite* _character_sprite = nullptr;
		HPBar* _hp_bar = nullptr;
		RiD::Movement* _movement = nullptr;
		Hitbox* _hitbox = nullptr;
		short _health_points;
		short _damage;
		sf::Vector2f _position;
		bool _is_alive;
		short _direction;
		float _speed;
		enum directions { up, left, down, right };
		bool _moving_up = true, _moving_down = true, _moving_right = true, _moving_left = true;

		sf::Vector2i _isoTo2D(sf::Vector2f position);
	public:

		//Sets character's position
		virtual void setPosition(sf::Vector2f position);

		//Function responsible for all of the moves
		virtual void update(sf::Time time, std::vector<std::vector<std::unique_ptr<MapElement>>>& map_objects,
			std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderWindow& window) = 0;

		//Draws character's sprite
		virtual void render(sf::RenderWindow& window);

		//Checks if character is alive
		virtual bool isAlive();

		//Gets character position
		virtual sf::Vector2f getPosition();

		//Checks if two objects collide witch each other
		bool checkOrientedCollision(const sf::RectangleShape& Object1, const sf::RectangleShape& Object2);

		//Subtracts character's hp
		virtual void subtractHP(short value);

		//Returns character's hitbox as rectangle
		virtual sf::RectangleShape getHitbox();

		//Dealing damage to bots of enemy team
		//@param time time needed for combat animations
		//@param list_of_bots list of possible enemies
		//@param window render window
		virtual void dealDamage(sf::Time time, std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderTarget& window) = 0;

		virtual void deadBody(sf::RenderWindow& window) = 0;
	};
}