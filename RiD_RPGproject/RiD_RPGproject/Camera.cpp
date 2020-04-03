#include <iostream>
#include "Camera.h"
#include "ActiveObiect.h"

void MP::Camera::_zoom_in()
{
	if (_view.getSize().x > _min_x_size)
	{
		_view = _window.getView();
		_view.zoom(0.9);
		_window.setView(_view);
	}
	std::cout << _view.getSize().x << " x " << _view.getSize().y << std::endl;
}

void MP::Camera::_zoom_out()
{
	if (_view.getSize().x < _max_x_size)
	{
		_view = _window.getView();
		_view.zoom(1.1);
		_window.setView(_view);
	}
	std::cout << _view.getSize().x << " x " << _view.getSize().y << std::endl;
}

MP::Camera::Camera()
{
	_min_x_size = RiD::ConfigurationLoader::getIntData("video settings", "minCameraView");
	_max_x_size = RiD::ConfigurationLoader::getIntData("video settings", "maxCameraView");
	_view.setSize(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth"), RiD::ConfigurationLoader::getIntData("video settings", "screenHeight"));
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
	if (aTaskManager.getTask() == MP::TaskManager::taskType::zoomOut)
		_zoom_out();
	if (aTaskManager.getTask() == MP::TaskManager::taskType::zoomIn)
		_zoom_in();

	aTaskManager.endTask();
}

void MP::Camera::changeCamera(sf::Vector2f coord)
{
	coord.x += 32;
	coord.y += 32;
	_view.setCenter(coord);
	_window.setView(_view);
}
