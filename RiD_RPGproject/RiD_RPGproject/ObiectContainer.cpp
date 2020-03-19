#include "ObiectContainer.h"
#include "Obiect.h" 

MP::ObiectContainer::ObiectContainer(Obiect *& newObiect)
{
	nextContainer = nullptr;
	aObiect = newObiect;
}

MP::ObiectContainer::~ObiectContainer()
{
	delete aObiect;
}
