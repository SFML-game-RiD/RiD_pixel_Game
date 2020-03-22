#ifndef _OBIECTCONTAINER_H_
#define _OBIECTCONTAINER_H_


#include "Obiect.h"
#include "Player.h"

namespace MP
{
	class ObiectContainer
	{
	public:
	
		ObiectContainer* nextContainer;
		
		std::shared_ptr<Obiect> aObiect;

		ObiectContainer(std::shared_ptr<Obiect>& newObiect);

		ObiectContainer(std::shared_ptr<Player> &newPlayer);
	};
}
#endif