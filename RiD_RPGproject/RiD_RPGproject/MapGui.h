#ifndef MAPGUI_H
#define MAPGUI_H
#include "Obiect.h"
#include "TaskManager.h"
#include "ItemsManager.h"

namespace MP

{
	class MapGui:public Obiect
	{
	private:

		void _draw_items(sf::RenderWindow &mainWindow, ItemsManager& aItemsManager);

		void _update_items(ItemsManager &aItemsManager);

	public:

		MapGui(sf::Texture* texturePtr);

		void render(sf::RenderWindow& mainWindow, ItemsManager& aItemsManager);

		void update(ItemsManager& aItemsManager);
		
	};
}
#endif // !_MAPGUI_H_
