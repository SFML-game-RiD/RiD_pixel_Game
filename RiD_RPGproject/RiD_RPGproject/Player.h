#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Move.h"
#include "PawnObiect.h"

namespace MP
{
	class Player :public PawnObiect
	{
	private:

		void _player_animation_right(sf::Clock& globalClock);

		void _player_animation_left(sf::Clock& globalClock);

		void _player_animation_up(sf::Clock& globalClock);

		void _player_animation_down(sf::Clock& globalClock);

	public:

		TaskManager aTaskManager;

		Player(sf::Texture *texturePtr);

		//############ move animation ##############

		void playerAnimation(sf::Clock& globalClock, MP::TaskManager& aTaskManager);

		//##########################################

	};


}
#endif