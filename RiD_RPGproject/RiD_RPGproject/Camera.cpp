#include <iostream>
#include "Camera.h"
#include "ActiveObiect.h"

void MP::Camera::_zoom_in(GuiManager& aGuiManager)
{
	if (_view.getSize().x > _min_x_size)
	{
		_view = _window.getView();
		//_view.zoom(0.9);
		_view.setSize(_view.getSize().x- 533.333333, _view.getSize().y-300); //I hope player won't see it :(
		aGuiManager.scaleGui(_view.getSize());

		_window.setView(_view);
	}
	std::cout << _view.getSize().x << " x " << _view.getSize().y << std::endl;
}

void MP::Camera::_zoom_out(GuiManager& aGuiManager)
{
	if (_view.getSize().x < _max_x_size)
	{
		_view = _window.getView();
		//_view.zoom(1.1);
		_view.setSize(_view.getSize().x+ 533.333333, _view.getSize().y+300); //I hope player won't see it :(
		aGuiManager.scaleGui(_view.getSize());
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

void MP::Camera::changeZoom(GuiManager& aGuiManager, MP::TaskManager& aTaskManager)
{
	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskZoomOut)
		_zoom_out(aGuiManager);
	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskZoomIn)
		_zoom_in(aGuiManager);

	aTaskManager.endTask();
}

void MP::Camera::changeCamera(GuiManager& aGuiManager, sf::Vector2f coord)
{
	aGuiManager.getMapGui()->setObiectCoord(coord);

	coord.x += 32;
	coord.y += 32;
	
	_view.setCenter(coord);
	_window.setView(_view);
}
