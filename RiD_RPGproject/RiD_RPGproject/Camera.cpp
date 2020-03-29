#include "Camera.h"

void MP::Camera::_zoom_in()
{

	_view= _window.getView();
	_view.zoom(0.9);
	_window.setView(_view);
}

void MP::Camera::_zoom_out()
{
	_view = _window.getView();
	_view.zoom(1.1);
	_window.setView(_view);
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
