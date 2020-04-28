#pragma once

#include <memory>
#include "Button.h"
#include "WindowBorder.h"
#include "Menu.h"
#include "Message.h"

namespace RTBGUI
{
	class GUI
	{
	private:
		sf::RenderWindow *_window;
		std::unique_ptr<Button> _button_yes, _button_no;
		std::unique_ptr<WindowBorder> _window_border;
		std::unique_ptr<Menu> _menu;
		std::unique_ptr<Message> _message;
		RiD::AssetManager _asset_manager;
		sf::Sprite _cursor, _menu_background;
		sf::View _camera, _gui;

		bool _is_paused;
	public:
		GUI(sf::RenderWindow& window);
		~GUI();

		void update(bool is_paused);

		void render();

		void setCameraZoom(float zoom);

		void setCameraCenter(sf::Vector2f center);

		sf::View getCamera();
	};
}