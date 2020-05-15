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

		void _draw_trees(TaskManager& aMainTaskManager, sf::RenderWindow& mainWindow, ObjectManager& aObiectManager);

		void _draw_grass(sf::RenderWindow& mainWindow, ObjectManager& aObiectManager);
		
		void _draw_active_obiects(TaskManager& aMainTaskManager, sf::RenderWindow& mainWindow, ObjectManager& aObiectManager);
		
	public:

		void drawGame(TaskManager& aMainTaskManager, Camera &aGameCamera, ObjectManager & aObiectManager);

	};

}