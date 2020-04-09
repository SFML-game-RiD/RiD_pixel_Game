#include "GuiManager.h"
#include <iostream>
MP::GuiManager::GuiManager()
{
	_last_camera_view_size= sf::Vector2f(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth"), RiD::ConfigurationLoader::getIntData("video settings", "screenHeight"));

}

std::unique_ptr<MP::MapGui>& MP::GuiManager::getMapGui()
{
	return _a_map_gui;
}

void MP::GuiManager::scaleGui(sf::Vector2f newCameraViewSize)
{
	//Calculating..
	sf::Vector2f oldGuiScale = _a_map_gui->aAnimation.getScale();
	std::cout << oldGuiScale.x << " <OLD SCALE> " << oldGuiScale.y << std::endl;


	double newScale = (oldGuiScale.x * newCameraViewSize.x) / _last_camera_view_size.x;
	std::cout << newScale << " <NEW SCALE> " << newScale << std::endl;
	_a_map_gui->aAnimation.setScale(newScale, newScale);
	_last_camera_view_size = newCameraViewSize;
}
