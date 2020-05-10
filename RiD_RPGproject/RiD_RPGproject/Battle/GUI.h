#pragma once

#include <memory>
#include "Button.h"
#include "WindowBorder.h"
#include "Menu.h"
#include "Message.h"
#include "Cursor.h"

namespace RTBGUI
{
	class GUI
	{
	private:
		sf::RenderWindow* _window;
		std::unique_ptr<Cursor> _cursor;
		std::shared_ptr<Button> _button_yes, _button_no, _button_ok;
		std::unique_ptr<WindowBorder> _window_border;
		std::unique_ptr<Menu> _menu;
		std::unique_ptr<Message> _message_menu, _message_lost, _message_won;
		RiD::AssetManager _asset_manager;
		sf::Sprite _menu_background, _lost_background, _won_background;
		sf::View _camera, _gui;
		sf::Event _event;
	public:
		GUI(sf::RenderWindow& window);
		~GUI();

		void update(bool& is_paused, bool& is_surrendered, bool ally_team_dead, bool enemy_team_dead, bool& return_from_battle);

		void render(bool& is_paused, bool& is_surrendered, bool ally_team_dead, bool enemy_team_dead);

		void setCameraZoom(float zoom);

		void setCameraCenter(sf::Vector2f center);

		sf::View getCamera();

		std::shared_ptr<Button> getButtonNo();

		std::shared_ptr<Button> getButtonYes();

		std::shared_ptr<Button> getButtonOk();
	};
}