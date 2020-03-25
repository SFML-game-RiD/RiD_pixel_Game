#ifndef _OBIECTMANAGER_H_
#define _OBIECTMANAGER_H_

#include <list>
#include "Player.h"
#include "Land.h"


namespace MP
{
	class ObiectManager
	{
	private:

		std::shared_ptr<Player> _player;
		std::list<Land> _land_list;


	public:
		
		ObiectManager();

		void addObiect(std::shared_ptr<Player> newPlayer);

		void addObiect(Land *& newLand );

		std::shared_ptr<Player> & getPlayer();
		std::list<Land> & getLandList();
	};

}
#endif