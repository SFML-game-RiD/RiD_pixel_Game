#pragma once

#include <random>
#include <list>
#include "Player.h"
#include "Land.h"
#include "Map.h"
#include "Tree.h"
#include "ComputerPlayerBandit.h"
#include "Cursor.h"
#include "GuiManager.h"
#include "Grass.h"

namespace MP
{
	class ObjectManager
	{
	private:

		//This two variables below should be exported to another class.
		int _mod_number;

		std::mt19937 _random_number;

		//OBIECTS

		std::shared_ptr<Player> _player;

		std::list<ComputerPlayerBandit> _computer_player_list;

		std::list<Tree> _tree_list;

		std::vector<Grass> _grass_list;
		
		std::shared_ptr<Cursor> _a_cursor;
	
		Map _a_map;

		GuiManager _a_gui_manager;

	public:
		
		ObjectManager();

		~ObjectManager();

		void addObiect(std::shared_ptr<Player> &newPlayer);
		
		void addObiect(ComputerPlayerBandit &newComputerPlayer);

		std::shared_ptr<Player> & getPlayer();
		
	
		Map& getMap();

		std::list<Tree> * getTreeList();

		std::vector<Grass>* getGrassVector();

		bool access();

		std::list<MP::ComputerPlayerBandit>* getComputerPlayerList();

		std::shared_ptr<Cursor>& getCursor();

		void setCursor(std::shared_ptr<Cursor> &aCursor);

		GuiManager& getGuiManager();
	};

}