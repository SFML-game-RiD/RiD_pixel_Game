#pragma once

#include "GUI.h"

namespace RTBGUI
{
	GUI::GUI(sf::RenderWindow& window) :
		_window(&window)
	{
		_asset_manager.setTexture("window_border", "img/WindowBorder.png");
		_asset_manager.setTexture("menu", "img/MenuWindow.png");
		_asset_manager.setTexture("cursor", "img/Hand.png");
		_asset_manager.setTexture("menu_background", "img/menu_background.png");

		_window_border.setTexture(_asset_manager.getTexture("window_border"));
		_menu.setTexture(_asset_manager.getTexture("menu"));
		_menu_background.setTexture(_asset_manager.getTexture("menu_background"));

		_window->setMouseCursorVisible(false);
		_cursor.setTexture(_asset_manager.getTexture("cursor"));
		_cursor.setOrigin(18.f, 14.f);

		_camera.reset(sf::FloatRect(0, 0, 1280, 720));
	}

	GUI::~GUI()
	{
		_window = nullptr;
	}

	void GUI::update(bool is_paused)
	{
		_is_paused = is_paused;
		sf::Vector2f center = _camera.getCenter();
		_window_border.setPosition(center.x - 640.f, center.y - 360.f);

		sf::Vector2f worldPos = _window->mapPixelToCoords(sf::Mouse::getPosition(*_window));
		_cursor.setPosition(worldPos);
		if (_is_paused)
		{
			_menu_background.setPosition(center.x - 640.f, center.y - 360.f);
			_menu.setPosition(center.x - 160.f, center.y - 240.f);
		}
	}

	void GUI::render()
	{
		_window->draw(_window_border);
		if (_is_paused)
		{
			_window->draw(_menu_background);
			_window->draw(_window_border);
			_window->draw(_menu);
		}
		_window->draw(_cursor);
	}

	void GUI::setCameraZoom(float zoom)
	{
		_camera.zoom(zoom);
	}

	void GUI::setCameraCenter(sf::Vector2f center)
	{
		_camera.setCenter(center);
	}

	sf::View GUI::getCamera()
	{
		return _camera;
	}
}