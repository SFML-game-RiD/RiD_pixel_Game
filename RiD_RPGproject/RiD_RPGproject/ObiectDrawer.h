#ifndef _OBIECTDRAWER_H_
#define _OBIECTDRAWER_H_

#include "ObiectManager.h"

namespace MP
{
	class ObiectDrawer
	{
	private:

		void _draw_land(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);

		void _draw_trees(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);

	public:

		void drawAllObiects(sf::RenderWindow& mainWindow, ObiectManager & aObiectManager);

		void drawActiveObiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);

		void _draw_cursor(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);

	};

}
#endif