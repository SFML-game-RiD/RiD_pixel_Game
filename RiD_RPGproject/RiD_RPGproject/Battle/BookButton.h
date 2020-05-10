#pragma once

#include "../Engine/AssetManager.h"

namespace RTBGUI
{
	class BookButton
	{
	private:
		sf::Sprite _book;
		RiD::AssetManager _asset_manager;
	public:
		BookButton();

		void update();

		void render();
	};
}