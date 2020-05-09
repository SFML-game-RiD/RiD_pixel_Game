#pragma once
#include <SFML/Graphics.hpp>
#include "PawnObject.h"
#include "PathCreator.h"
#include "Player.h"

namespace MP
{
	class ComputerPlayerBandit:public PawnObject
	{
	private:

		MapElement* _path;

		int _radius;

		bool _is_enemys_check;

		void _computer_player_animation_right(sf::Clock& globalClock);

		void _computer_player_animation_left(sf::Clock& globalClock);

		void _computer_player_animation_up(sf::Clock& globalClock);

		void _computer_player_animation_down(sf::Clock& globalClock);

		void _computer_player_animation(sf::Clock& globalClock);

		void _computer_player_move(sf::Clock& globalClock);

		void _get_next_task(Map& aMap);

		void _chose_destination(Map& aMap);

		void _delete_path();

		bool _check_enemy(std::shared_ptr<Player>& aPlayer);

		void _song_procedure(MP::SoundManager& aSoundManager);

	public:

		ComputerPlayerBandit(sf::Texture* texturePtr);

		~ComputerPlayerBandit();

		void update(SoundManager& aSoundManager, Map& aMap, sf::Clock& gameClock, std::shared_ptr<Player>& aPlayer);

		void render(sf::RenderWindow &mainWindow);

	};

}