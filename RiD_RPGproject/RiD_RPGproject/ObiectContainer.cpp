#include "ObiectContainer.h"
#include "Obiect.h" 
#include "Player.h"

MP::ObiectContainer::ObiectContainer(std::shared_ptr<Obiect> &newObiect)
{
	nextContainer = nullptr;
	aObiect = newObiect;
}

MP::ObiectContainer::ObiectContainer(std::shared_ptr<Player> &newPlayer)
{
	nextContainer = nullptr;
	aObiect =newPlayer;

	nextContainer = nullptr;
}
