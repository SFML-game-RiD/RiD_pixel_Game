#include <iostream>
#include "Camera.h"
#include "ActiveObiect.h"

void MP::Camera::_zoom_in()
{
	if (_game_view.getSize().x > _min_x_size)
	{
		_game_view = _window.getView();
		_game_view.setSize(_game_view.getSize().x- 266.66655, _game_view.getSize().y-150); //I hope player won't see it :(

		_window.setView(_game_view);
	}
	std::cout << _game_view.getSize().x << " x " << _game_view.getSize().y << std::endl;
}

void MP::Camera::_zoom_out()
{
	if (_game_view.getSize().x < _max_x_size)
	{
		_game_view = _window.getView();
		_game_view.setSize(_game_view.getSize().x+ 266.66655, _game_view.getSize().y+150); //I hope player won't see it :(
		_window.setView(_game_view);
	}
	std::cout << _game_view.getSize().x << " x " << _game_view.getSize().y << std::endl;
}

MP::Camera::Camera()
{
	_min_x_size = RiD::ConfigurationLoader::getIntData("video settings", "minCameraView");
	_max_x_size = RiD::ConfigurationLoader::getIntData("video settings", "maxCameraView");
	_game_view.setSize(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth"), RiD::ConfigurationLoader::getIntData("video settings", "screenHeight"));
	_gui_view.setSize(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth"), RiD::ConfigurationLoader::getIntData("video settings", "screenHeight"));

}

sf::RenderWindow& MP::Camera::getWindow()
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

	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskZoomOut)
		_zoom_out();
	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskZoomIn)
		_zoom_in();

	aTaskManager.endTask();
}

void MP::Camera::changeCamera(sf::Vector2f coord)
{
	//Correcting camera position
	coord.x += 0;
	coord.y += 0;
	
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
