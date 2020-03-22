#ifndef _OBIECTDRAWER_H_
#define _OBIECTDRAWER_H_

#include "ObiectContainer.h"

namespace MP
{
	class ObiectDrawer
	{
	private:
		
		ObiectContainer* _active_obiects_list;

		ObiectContainer* _static_obiects_list;

	public:

		void drawAllObiects(sf::RenderWindow& mainWindow);

		void drawActiveObiects(sf::RenderWindow& mainWindow);

		void addObiect(ObiectContainer*& head, ObiectContainer*& obiect);

		void deleteObiects(ObiectContainer*& head);

		ObiectContainer*& getActiveObiectsList();

		ObiectContainer*& getStaticObiectsList();
	};

}
#endif