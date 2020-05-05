#pragma once
#include "Object.h"
#include "TaskManager.h"
#include "ItemsManager.h"

namespace MP

{
	class MapGui:public Object
	{
	private:

		//Draws items.
		//@param mainWindow game window.
		//@param aItemsManager items manager.
		void _draw_items(sf::RenderWindow &mainWindow, ItemsManager& aItemsManager);
		
		//Updates items.
		//@param aItemsManager items manager.
		void _update_items(ItemsManager &aItemsManager);

	public:

		//Gui's constructor.
		//@param texturePtr object's texture.
		MapGui(sf::Texture* texturePtr);

		//@param mainWindow game window.
		//@param aItemsManager items manager.
		void render(sf::RenderWindow& mainWindow, ItemsManager& aItemsManager);

		//Updates gui.
		//@param aItemsManager items manager.
		void update(ItemsManager& aItemsManager);
		
	};
}