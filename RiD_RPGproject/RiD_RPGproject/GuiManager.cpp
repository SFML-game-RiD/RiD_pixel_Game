#include "GuiManager.h"

MP::GuiManager::GuiManager()
{
	_last_camera_view_size= sf::Vector2f(float(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth")), float(RiD::ConfigurationLoader::getIntData("video settings", "screenHeight")));

}

std::unique_ptr<MP::MapGui>& MP::GuiManager::getMapGui()
{
	return _a_map_gui;
}

std::unique_ptr<MP::GuiMainMenu>& MP::GuiManager::getGuiMainMenu()
{
	return _a_gui_main_menu;
}

std::unique_ptr<MP::GuiPlacesMenu>& MP::GuiManager::getGuiPlacesMenu()
{
	return _a_gui_places_menu;
}

std::unique_ptr<MP::GuiMarketPlace>& MP::GuiManager::getGuiMarketPlace()
{
	return _a_gui_market_place;
}
