#pragma once

#include <list>
#include "Character.h"
#include "Bot.h"
#include "SwordHitbox.h"
#include "Arrow.h"


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

		void _dealSwordDamage(std::list<Bot*>& list_of_bots);
	public:
		Player(sf::Texture texture, short health_points, sf::Texture& arrow_texture);
		~Player();

		//Sets player position
		void setPosition(sf::Vector2f position);

		//Function responsible for all of the player moves and behaviors
		void update(sf::Time time);

		//Draws player sprite
		void render(sf::RenderWindow& window);

		//Checks if character is alive
		bool isAlive();

		//Gets player position
		sf::Vector2f getPosition();

		void dealDamage(sf::Time time, std::list<Bot*>& list_of_bots, sf::RenderTarget& window);
	};
}