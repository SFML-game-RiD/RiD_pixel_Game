#pragma once

#include "Obiect.h"

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

		~ObiectContainer();
	};
}
