#ifndef  COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <SFML/Graphics.hpp>
#include "PawnObiect.h"
#include "pathCreator.h"

namespace MP
{
	class ComputerPlayer:public PawnObiect
	{
	private:

		MapElement* _path;

		void _computer_player_animation_right(sf::Clock& globalClock);

		void _computer_player_animation_left(sf::Clock& globalClock);

		void _computer_player_animation_up(sf::Clock& globalClock);

		void _computer_player_animation_down(sf::Clock& globalClock);

		void _computer_player_animation(sf::Clock& globalClock);

		void _computer_player_move(sf::Clock& globalClock);

		void _get_next_task(Map& aMap);

		void _chose_destination(Map& aMap);

		void _delete_path();

	public:

		ComputerPlayer(sf::Texture* texturePtr);
		~ComputerPlayer();

		void update(Map& aMap, sf::Clock& gameClock);

		void render(sf::RenderWindow &mainWindow);

	};

}
#endif // ! _COMPUTER_PLAYER_H_