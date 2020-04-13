#ifndef _MAPGUI_H_
#define _MAPGUI_H_
#include "Obiect.h"
#include "TaskManager.h"
#include "ItemsManager.h"

namespace MP

{
	class MapGui:public Obiect
	{
	private:

		void _draw_items(sf::RenderWindow &mainWindow, ItemsManager& aItemsManager);

	public:

		MapGui(sf::Texture* texturePtr);

		void updateItems(ItemsManager &aItemsManager);

		void drawMapGui(sf::RenderWindow& mainWindow, ItemsManager& aItemsManager);

	};
}
#endif // !_MAPGUI_H_