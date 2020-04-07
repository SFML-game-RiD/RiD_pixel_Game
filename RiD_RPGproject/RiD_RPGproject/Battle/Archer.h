#pragma once

#include "Character.h"

namespace RTB
{
	class Archer :
		public Character
	{
	private:
		Arrow* _arrows = nullptr;
		short _arrows_count;
	public:
		Archer(sf::Texture texture, short health_points, sf::Texture& arrow_texture);
		~Archer();

		//Function responsible for all of the player moves and behaviors
		void update(sf::Time time, std::vector<std::vector<_obj>>& map_objects);

		//Dealing damage to bots of enemy team
		//@param time time needed for combat animations
		//@param list_of_bots list of possible enemies
		//@param window render window
		void dealDamage(sf::Time time, std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderTarget& window);

		//Draws Archer's sprite
		void render(sf::RenderWindow& window);
	};
}