#include <SFML/Graphics.hpp>
#include "ObiectManager.h"

MP::ObiectManager::ObiectManager()
{ 
	_player = nullptr;
}

void MP::ObiectManager::addObiect(std::shared_ptr<Player> newPlayer)
{
	_player = newPlayer;
}

void MP::ObiectManager::addObiect(Land *& newLand)
{
	_land_list.push_back(*newLand);
}

std::shared_ptr<MP::Player> & MP::ObiectManager::getPlayer()
{
	return _player;
}

std::list<MP::Land> & MP::ObiectManager::getLandList()
{
	return _land_list;
}
