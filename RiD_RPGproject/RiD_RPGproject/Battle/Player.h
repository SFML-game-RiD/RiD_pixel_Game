#pragma once

#include "Character.h"
#include <memory>

namespace RTB
{
	class Player
		:public Character
	{
	private:
		Arrow* _arrows = nullptr;
		short _arrows_count;
		sf::Vector2i _shot_destination;
		void _dealSwordDamage(std::list<std::shared_ptr<Character>>& list_of_bots);
		void _dealBowDamage(std::list<std::shared_ptr<Character>>& list_of_bots);
		void _isColidingWithTile(std::vector<std::vector<std::unique_ptr<MapElement>>>& map_objects);
	public:
		Player(sf::Texture texture, short health_points, sf::Texture& arrow_texture);
		~Player();

		//Function responsible for all of the player moves and behaviors
		void update(sf::Time time, std::vector<std::vector<std::unique_ptr<MapElement>>>& map_objects,
			std::list<std::shared_ptr<Character>>& list_of_bots,sf::RenderWindow& window);

		//Dealing damage to bots of enemy team
		//@param time time needed for combat animations
		//@param list_of_bots list of possible enemies
		//@param window render window
		void dealDamage(sf::Time time, std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderTarget& window);

		void deadBody(sf::RenderWindow& window);
	};
}