#ifndef OBIECTDRAWER_H
#define OBIECTDRAWER_H

#include "ObiectManager.h"
#include "Camera.h"

namespace MP
{
	class ObiectDrawer
	{
	private:

		void _draw_land(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);

		void _draw_trees(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);

		void _draw_cursor(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);
		
		void _draw_active_obiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);

		void _draw_map_gui(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);
		
		void _draw_map_gui_obiects(sf::RenderWindow& mainWindow, ObiectManager& aObiectManager);

	public:

		void drawAllObiects(TaskManager& aMainTaskManager, Camera &aGameCamera, ObiectManager & aObiectManager);

		void drawMenu(TaskManager &aMainTaskManager , ObiectManager& aObiectManager, Camera& aGameCamera);

	

	};

}
#endif