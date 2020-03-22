#ifndef _OBIECTMANAGER_H_
#define _OBIECTMANAGER_H_


#include "Player.h"



namespace MP
{
	class ObiectManager
	{
	private:

		std::shared_ptr<Player> _player;

	public:
		
		void addObiect(std::shared_ptr<Player> newPlayer);

		std::shared_ptr<Player> & getPlayer();
	
	};

}
#endif