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

std::shared_ptr<MP::Player> & MP::ObiectManager::getPlayer()
{
	return _player;
}

MP::MapElement* MP::ObiectManager::getMapElementHead()
{
	return _a_Map.getMapElementList();
}
