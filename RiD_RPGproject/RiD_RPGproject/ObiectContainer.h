#pragma once

#include "Obiect.h"
#include "Player.h"

namespace MP
{
	class ObiectContainer
	{
	public:
		//enum ObiectType
		//{

		//};

		ObiectContainer* nextContainer;
		
		//ObiectType type;

		Obiect * aObiect;

		ObiectContainer(Obiect *& newObiect);

		ObiectContainer(Player*& newPlayer);

		~ObiectContainer();
	};
}
