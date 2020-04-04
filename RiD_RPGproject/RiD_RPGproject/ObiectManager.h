#ifndef _OBIECTMANAGER_H_
#define _OBIECTMANAGER_H_

#include <random>
#include <list>
#include "Player.h"
#include "Land.h"
#include "Map.h"
#include "Tree.h"
#include "ComputerPlayer.h"

namespace MP
{
	class ObiectManager
	{
	private:

		int _mod_number;

		std::mt19937 _random_number;

		//OBIECTS

		std::shared_ptr<Player> _player;

		std::shared_ptr<ComputerPlayer> _computer_player;

		std::list<Tree> _tree_list;

		Map _a_map;


	

	public:
		
		ObiectManager();

		~ObiectManager();

		void addObiect(std::shared_ptr<Player> newPlayer);
		
		void addObiect(std::shared_ptr<ComputerPlayer> newComputerPlayer);

		std::shared_ptr<Player> & getPlayer();
		
		MapElement *& getMapElementHead();
	
		Map& getMap();

		std::list<Tree> * getTreeList();

		bool _access();

		std::shared_ptr<ComputerPlayer>& getComputerPlayer();
	};

}
#endif