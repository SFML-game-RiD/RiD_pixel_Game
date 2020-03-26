#ifndef _OBIECTMANAGER_H_
#define _OBIECTMANAGER_H_

#include <list>
#include "Player.h"
#include "Land.h"
#include "Map.h"


namespace MP
{
	class ObiectManager
	{
	private:

		std::shared_ptr<Player> _player;

		Map _a_Map;

	public:
		
		ObiectManager();

		void addObiect(std::shared_ptr<Player> newPlayer);

		std::shared_ptr<Player> & getPlayer();

		MapElement* getMapElementHead();
	};

}
#endif