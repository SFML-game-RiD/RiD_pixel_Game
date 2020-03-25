#ifndef _OBIECTDRAWER_H_
#define _OBIECTDRAWER_H_

#include "ObiectManager.h"

namespace MP
{
	class ObiectDrawer
	{
	private:

	public:

		void drawAllObiects(sf::RenderWindow& mainWindow, ObiectManager & aObiectManager);

		void drawActiveObiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);

	};

}
#endif