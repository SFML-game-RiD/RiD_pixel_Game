#ifndef OBIECTMANAGER_H
#define OBIECTMANAGER_H

#include <random>
#include <list>
#include "Player.h"
#include "Land.h"
#include "Map.h"
#include "Tree.h"
#include "ComputerPlayer.h"
#include "Cursor.h"
#include "GuiManager.h"

namespace MP
{
	class ObiectManager
	{
	private:

		int _mod_number;

		std::mt19937 _random_number;

		//OBIECTS

		std::shared_ptr<Player> _player;

		std::list<ComputerPlayer> _computer_player_list;

		std::list<Tree> _tree_list;

		Map _a_map;

		std::shared_ptr<Cursor> _a_cursor;

		GuiManager _a_gui_manager;

	public:
		
		ObiectManager();

		~ObiectManager();

		void addObiect(std::shared_ptr<Player> newPlayer);
		
		void addObiect(ComputerPlayer newComputerPlayer);

		std::shared_ptr<Player> & getPlayer();
		
		MapElement *& getMapElementHead();
	
		Map& getMap();

		std::list<Tree> * getTreeList();

		bool _access();

		std::list<MP::ComputerPlayer>* getComputerPlayerList();

		std::shared_ptr<Cursor>& getCursor();

		void setCursor(std::shared_ptr<Cursor> &aCursor);

		GuiManager& getGuiManager();
	};

}
#endif