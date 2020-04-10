#ifndef _GUIMANAGER_H_
#define _GUIMANAGER_H_
#include "MapGui.h"
#include "GuiMenu.h"

namespace MP
{
	class GuiManager
	{
	private:

		sf::Vector2f _last_camera_view_size;

		std::unique_ptr<MapGui> _a_map_gui;

		std::unique_ptr<GuiMenu> _a_gui_main_menu;

		std::unique_ptr<GuiMenu> _a_gui_places_menu;

	public:

		GuiManager();

		std::unique_ptr<MapGui>& getMapGui();

		std::unique_ptr<GuiMenu>& getGuiMainMenu();

		std::unique_ptr<GuiMenu>& getGuiPlacesMenu();

	};
}
#endif // !_GUIMANAGER_H_
