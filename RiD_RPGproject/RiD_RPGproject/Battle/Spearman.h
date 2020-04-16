#pragma once

#include "Character.h"
#include "RTBPathGenerator.h"

namespace RTB
{
	class Spearman :
		public Character
	{
	private:
		AI::RTBPathGenerator* _path_generator = nullptr;
		RiD::Movement* _movement = nullptr;
		Hitbox* _hitbox = nullptr;
		HPBar* _hp_bar = nullptr;
		AI::PathNode* _current_path = nullptr, * _tmp_current_path = nullptr, * _half_way = nullptr;
		sf::Vector2i _current_enemy_position, _end_path_position;
		bool _is_enemy_choosen;
		std::list<std::shared_ptr<Character>>::iterator _choosen_enemy;

		void _dealSwordDamage(std::list<std::shared_ptr<Character>>& list_of_bots);
		std::list<std::shared_ptr<Character>>::iterator _selectRandomEnemy(std::list<std::shared_ptr<Character>>::iterator start, std::list<std::shared_ptr<Character>>::iterator end);
	public:
		Spearman(sf::Texture texture, short health_points, std::vector<std::vector<AI::PathNode>>& walkable_area);
		~Spearman();

		//Sets Swordsmans position
		void setPosition(sf::Vector2f position);

		//Function responsible for all of the Swordsmans moves and behaviors
		void update(sf::Time time, std::vector<std::vector<std::unique_ptr<MapElement>>>& map_objects,
			std::list<std::shared_ptr<Character>>& list_of_bots, sf::RenderWindow& window);

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

		void delete_path();

		void deadBody(sf::RenderWindow& window);
	};
}