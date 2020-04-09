#ifndef _GUIMANAGER_H_
#define _GUIMANAGER_H_
#include "MapGui.h"


namespace MP
{
	class GuiManager
	{
	private:

		sf::Vector2f _last_camera_view_size;

		std::unique_ptr<MapGui> _a_map_gui;

	public:

		GuiManager();

		std::unique_ptr<MapGui>& getMapGui();

		void scaleGui(sf::Vector2f newCameraViewSize);

	};
}
#endif // !_GUIMANAGER_H_
