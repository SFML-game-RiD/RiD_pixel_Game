#include <iostream>
#include "Camera.h"
#include "ActiveObiect.h"

void MP::Camera::_zoom_in()
{
	if (_game_view.getSize().x > _min_x_size)
	{
		_game_view = _window.getView();
		_game_view.zoom(0.8);
		_window.setView(_game_view);
	}

}

void MP::Camera::_zoom_out()
{
	if (_game_view.getSize().x < _max_x_size)
	{
		_game_view = _window.getView();
		_game_view.zoom(1.2);
		_window.setView(_game_view);
	}

}

MP::Camera::Camera()
{
	_min_x_size = RiD::ConfigurationLoader::getIntData("video settings", "minCameraView");
	_max_x_size = RiD::ConfigurationLoader::getIntData("video settings", "maxCameraView");
	_game_view.setSize(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth")*0.78125, RiD::ConfigurationLoader::getIntData("video settings", "screenHeight"));
	_gui_view.setSize(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth"), RiD::ConfigurationLoader::getIntData("video settings", "screenHeight"));

	_game_view.setViewport(sf::FloatRect(0, 0, 0.78125, 1)); //Computer will not drawing frames behind gui
	_gui_view.setViewport(sf::FloatRect(0, 0, 1, 1));
}

sf::RenderWindow & MP::Camera::getWindow()
{
	return _window;
}

void MP::Camera::clearCamera()
{
	_window.clear();
}

void MP::Camera::drawFrame()
{
	_window.display();
}

void MP::Camera::changeZoom(MP::TaskManager& aTaskManager)
{
	changeViewToGame();

	if (aTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskZoomOut)
		_zoom_out();
	if (aTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskZoomIn)
		_zoom_in();

	aTaskManager.endTask(MP::TaskManager::taskRange::order);
}

void MP::Camera::changeCamera(sf::Vector2f coord)
{
	//Correcting camera position
	coord.x += 30;
	coord.y += 30;
	
	_game_view.setCenter(coord);
	_window.setView(_game_view);

}

void MP::Camera::changeViewToGame()
{
	_window.setView(_game_view);
}

void MP::Camera::changeViewToGui()
{
	_window.setView(_gui_view);
}
