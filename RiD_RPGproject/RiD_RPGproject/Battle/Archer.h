#pragma once

#include <algorithm> 
#include "Character.h"
#include "RTBPathGenerator.h"

namespace RTB
{
	class Archer :
		public Character
	{
	private:
		AI::RTBPathGenerator* _path_generator = nullptr;
		Arrow* _arrows = nullptr;
		short _arrows_count;
		AI::PathNode* _current_path = nullptr, * _tmp_current_path = nullptr, * _half_way = nullptr;
		sf::Vector2i _current_enemy_position, _end_path_position, _attack_position;
		bool _is_enemy_choosen;
		sf::Vector2i _shot_destination;
		std::list<std::shared_ptr<Character>>::iterator _choosen_enemy;

		std::list<std::shared_ptr<Character>>::iterator _selectRandomEnemy(std::list<std::shared_ptr<Character>>::iterator start, std::list<std::shared_ptr<Character>>::iterator end);
		void _dealBowDamage(std::list<std::shared_ptr<Character>>& list_of_bots);
		sf::Vector2i _findAttackPosition(int width, int height);
	public:
		Archer(sf::Texture texture, short health_points, sf::Texture& arrow_texture, std::vector<std::vector<AI::PathNode>>& walkable_area);
		~Archer();

		//Function responsible for all of the player moves and behaviors
		void update(sf::Time time, std::vector<std::vector<std::unique_ptr<MapElement>>>& map_objects,
			std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderWindow& window);

		//Dealing damage to bots of enemy team
		//@param time time needed for combat animations
		//@param list_of_bots list of possible enemies
		//@param window render window
		void dealDamage(sf::Time time, std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderTarget& window);

		//Draws Archer's sprite
		void render(sf::RenderWindow& window);

		void delete_path();

		void deadBody(sf::RenderWindow& window);
	};
}