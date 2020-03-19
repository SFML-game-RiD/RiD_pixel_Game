#pragma once
#include "Obiect.h"
#include "ObiectContainer.h"

namespace MP
{
	class ObiectManager
	{
	public:
		
		

		ObiectContainer * activeObiectList;
		ObiectContainer * staticObiectList;

		ObiectManager();

		~ObiectManager();

		void drawAllObiects(sf::RenderWindow & mainWindow);

		void drawActiveObiects(sf::RenderWindow & mainWindow);

		void addObiect(ObiectContainer*& head, ObiectContainer *& obiect);

		void deleteObiects(ObiectContainer*& head);

		void generateObiects();
	};

}
