#pragma once
#include "Player.h"
#include "ObiectContainer.h"

namespace MP
{
	class ObiectManager
	{
	private:

		Player* player;

		ObiectContainer* activeObiectList;
		ObiectContainer* staticObiectList;

	public:
		
		MP::Player* getPlayerPtr();

		ObiectManager();

		~ObiectManager();

		void drawAllObiects(sf::RenderWindow & mainWindow);

		void drawActiveObiects(sf::RenderWindow & mainWindow);

		void addObiect(ObiectContainer*& head, ObiectContainer *& obiect);

		void deleteObiects(ObiectContainer*& head);

		void generateObiects();
	};

}
