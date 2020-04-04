#pragma once

#include <list>
#include "Character.h"
#include "Bot.h"
#include "SwordHitbox.h"
#include "Arrow.h"
#include "../Map/TileMap.h"
#include "OrientedHitbox.h"


namespace RTB
{
	class Player
		:Character
	{
	private:
		RiD::Movement* _movement = nullptr;
		Hitbox* _hitbox = nullptr;
		SwordHitbox* _sword_hitbox = nullptr;
		HPBar* _hp_bar = nullptr;
		Arrow* _arrows = nullptr;
		enum directions { up, left, down, right };
		short _direction;
		bool _moving_up = true, _moving_down = true, _moving_right = true, _moving_left = true;

		void _dealSwordDamage(std::list<Bot*>& list_of_bots);
		void _dealBowDamage(std::list<Bot*>& list_of_bots);
		void _isColidingWithTile(std::vector<std::vector<_obj>>& map_objects);
	public:
		Player(sf::Texture texture, short health_points, sf::Texture& arrow_texture);
		~Player();

		//Sets player position
		void setPosition(sf::Vector2f position);

		//Function responsible for all of the player moves and behaviors
		void update(sf::Time time, std::vector<std::vector<_obj>>& map_objects);

		//Draws player sprite
		void render(sf::RenderWindow& window);

		//Checks if character is alive
		bool isAlive();

		//Gets player position
		sf::Vector2f getPosition();

		//Dealing damage to bots of enemy team
		//@param time time needed for combat animations
		//@param list_of_bots list of possible enemies
		//@param window render window
		void dealDamage(sf::Time time, std::list<Bot*>& list_of_bots, sf::RenderTarget& window);

		bool checkMapCollision(const sf::RectangleShape& Object1, const sf::RectangleShape& Object2);
	};
}