#include "ObiectContainer.h"
#include "Obiect.h" 
#include "Player.h"

MP::ObiectContainer::ObiectContainer(Obiect *& newObiect)
{
	nextContainer = nullptr;
	aObiect = newObiect;
}

MP::ObiectContainer::ObiectContainer(Player *& newObiect)
{
	nextContainer = nullptr;
	aObiect = newObiect;
}

MP::ObiectContainer::~ObiectContainer()
{
	delete aObiect;
}
