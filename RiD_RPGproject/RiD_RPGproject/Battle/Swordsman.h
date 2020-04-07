#pragma once

#include "Character.h"

namespace RTB
{
	class Swordsman
		:public Character
	{
	private:
		RiD::Movement* _movement = nullptr;
		Hitbox* _hitbox = nullptr;
		HPBar* _hp_bar = nullptr;
	public:
		Swordsman(sf::Texture texture, short health_points);
		~Swordsman();

		//Sets Swordsmans position
		void setPosition(sf::Vector2f position);

		//Function responsible for all of the Swordsmans moves and behaviors
		void update(sf::Time time, std::vector<std::vector<_obj>>& map_objects);

		//Draws Swordsmans sprite
		void render(sf::RenderWindow& window);

		//Checks if character is alive
		bool isAlive();

		//Gets Swordsmans position
		sf::Vector2f getPosition();

		//Gets Swordsman hitbox
		sf::RectangleShape getHitbox();

		//Dealing damage to Swordsmans of enemy team
		//@param time time needed for combat animations
		//@param list_of_Swordsmans list of possible enemies
		//@param window render window
		void dealDamage(sf::Time time, std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderTarget& window);

		//Subtracts health points
		void subtractHP(short value);
	};
}