#include "GuiManager.h"

MP::GuiManager::GuiManager()
{
	_last_camera_view_size= sf::Vector2f(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth"), RiD::ConfigurationLoader::getIntData("video settings", "screenHeight"));

}

std::unique_ptr<MP::MapGui>& MP::GuiManager::getMapGui()
{
	return _a_map_gui;
}