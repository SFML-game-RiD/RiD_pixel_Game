#pragma once
#include "ObjectManager.h"
#include "Camera.h"
#include "MapElement.h"

namespace MP
{
	class ObjectDrawer
	{
	private:

		void _draw_land(sf::RenderWindow& mainWindow, ObjectManager& aObiectManager);

		void _draw_trees(sf::RenderWindow& mainWindow, ObjectManager& aObiectManager);
		
		void _draw_active_obiects(sf::RenderWindow& mainWindow, ObjectManager& aObiectManager);
		
	public:

		void drawGame(TaskManager& aMainTaskManager, Camera &aGameCamera, ObjectManager & aObiectManager);

		void drawMenu(TaskManager &aMainTaskManager , ObjectManager& aObiectManager, Camera& aGameCamera);

	

	};

}