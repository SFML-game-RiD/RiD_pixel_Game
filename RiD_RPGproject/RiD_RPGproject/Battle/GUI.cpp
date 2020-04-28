#pragma once

#include "GUI.h"

namespace RTBGUI
{
	GUI::GUI(sf::RenderWindow& window) :
		_window(&window), _is_paused(false)
	{
		_window_border = std::make_unique<WindowBorder>();
		_menu = std::make_unique<Menu>();
		_button_yes = std::make_unique<Button>("YES");
		_button_no = std::make_unique<Button>("NO");
		_message = std::make_unique<Message>("  Do you really \nwant to surrender?", 40);

		_asset_manager.setTexture("cursor", "img/Hand.png");
		_asset_manager.setTexture("menu_background", "img/menu_background.png");
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
		sf::Vector2f worldPos = _window->mapPixelToCoords(sf::Mouse::getPosition(*_window));
		_cursor.setPosition(worldPos);

		_window_border->update(sf::Vector2f(center.x - 640.f, center.y - 360.f));
		if (_is_paused)
		{
			_message->update(sf::Vector2f(center.x - 139.f, center.y - 100.f));
			_menu_background.setPosition(center.x - 640.f, center.y - 360.f);
			_menu->update(sf::Vector2f(center.x - 160.f, center.y - 240.f));
			_button_yes->update(sf::Vector2f(center.x - 139.f, center.y + 40.f));
			_button_no->update(sf::Vector2f(center.x - 139.f, center.y + 100.f));

			if (_button_no->getSprite().getGlobalBounds().contains(worldPos))
				_button_no->setHovered(true);
			else if (_button_yes->getSprite().getGlobalBounds().contains(worldPos))
				_button_yes->setHovered(true);
		}
	}

	void GUI::render()
	{
		_window_border->render(_window);
		if (_is_paused)
		{
			_window->draw(_menu_background);
			_window_border->render(_window);
			_menu->render(_window);
			_button_yes->render(_window);
			_button_no->render(_window);
			_message->render(_window);
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