#ifndef _OBIECTMANAGER_H_
#define _OBIECTMANAGER_H_

#include <random>
#include <list>
#include "Player.h"
#include "Land.h"
#include "Map.h"
#include "Tree.h"


namespace MP
{
	class ObiectManager
	{
	private:

		int _mod_number;

		std::mt19937 _random_number;

		std::shared_ptr<Player> _player;

		std::list<Tree> _tree_list;

		Map _a_Map;


	

	public:
		
		ObiectManager();

		~ObiectManager();

		void addObiect(std::shared_ptr<Player> newPlayer);

		std::shared_ptr<Player> & getPlayer();
		
		MapElement* getMapElementHead();
	
		std::list<Tree> * getTreeList();

		bool _access();
	};

}
#endif