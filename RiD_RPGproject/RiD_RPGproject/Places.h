#pragma once
#include <SFML/Graphics.hpp>
#include "ActiveObject.h"

namespace MP
{
	class Places:public ActiveObject
	{
	private:

		ItemsManager itemsForTrade;///Manages items.

	public:

		//Place's constructor.
		Places();

		//Returns place's items.
		//@return return items.
		ItemsManager & getItemsForTrade();

		//Updates place.
		void update();

		//Draws object on screen.
		//@param mainWindow game window.
		void render(sf::RenderWindow& mainWindow);
	};
}
