#pragma once

#include "SFML/Graphics.hpp"
#include "../Engine/AssetManager.h"

namespace RTBGUI
{
	class GUI
	{
	private:
		sf::RenderWindow *_window;
		RiD::AssetManager _asset_manager;
		sf::Sprite _window_border, _cursor, _menu, _menu_background;
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