#include <SFML/Graphics.hpp>
#include "ObiectManager.h"

void MP::ObiectManager::addObiect(std::shared_ptr<Player> newPlayer)
{
	_player = newPlayer;
}

std::shared_ptr<MP::Player> & MP::ObiectManager::getPlayer()
{
	return _player;
}
