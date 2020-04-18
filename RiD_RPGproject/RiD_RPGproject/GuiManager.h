#ifndef GUIMANAGER_H
#define GUIMANAGER_H
#include "MapGui.h"
#include "GuiMainMenu.h"
#include "GuiMarketPlace.h"

namespace MP
{
	class GuiManager
	{
	private:

		sf::Vector2f _last_camera_view_size;

		std::unique_ptr<MapGui> _a_map_gui;

		std::unique_ptr<GuiMenu> _a_gui_main_menu;

		std::unique_ptr<GuiMenu> _a_gui_places_menu;

		std::unique_ptr<GuiMarketPlace> _a_gui_market_place;

	public:

		GuiManager();

		std::unique_ptr<MapGui>& getMapGui();

		std::unique_ptr<GuiMenu>& getGuiMainMenu();

		std::unique_ptr<GuiMenu>& getGuiPlacesMenu();

		std::unique_ptr<MP::GuiMarketPlace>& getGuiMarketPlace();

	};
}
#endif // !_GUIMANAGER_H_
