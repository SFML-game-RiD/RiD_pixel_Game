#ifndef  _CONPUTER_PLAYER_H_
#define _CONPUTER_PLAYER_H_

#include <SFML/Graphics.hpp>
#include "PawnObiect.h"
#include "pathCreator.h"
#include "TaskManager.h"

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

	public:

		TaskManager aTaskManager;

		ComputerPlayer(sf::Texture* texturePtr);

		//############ move animation ##############

		void computerPlayerAnimation(sf::Clock& globalClock);

		//##########################################

		void choseDestination(Map& aMap);

		void getNextTask(Map& aMap);

		void computerPlayerMove(sf::Clock& globalClock);
	};

}
#endif // ! _CONPUTER_PLAYER_H_