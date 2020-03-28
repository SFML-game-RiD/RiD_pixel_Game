#include <SFML/Graphics.hpp>
#include "ObiectManager.h"

bool MP::ObiectManager::_access()
{
	if (1 == _random_number() % _mod_number)
		return true;
	else
		return false;
}

MP::ObiectManager::ObiectManager()
{ 
	_mod_number = RiD::ConfigurationLoader::getIntData("game settings", "randModulo");
	_player = nullptr;
}

MP::ObiectManager::~ObiectManager()
{
	_tree_list.clear();
}

void MP::ObiectManager::addObiect(std::shared_ptr<Player> newPlayer)
{
	_player = newPlayer;
}

std::shared_ptr<MP::Player> & MP::ObiectManager::getPlayer()
{
	return _player;
}

MP::MapElement* MP::ObiectManager::getMapElementHead()
{
	return _a_Map.getMapElementList();
}

std::list<MP::Tree> * MP::ObiectManager::getTreeList()
{
	return &_tree_list;
}
