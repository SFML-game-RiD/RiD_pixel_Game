#ifndef GUIMARKETPLACE_H
#define GUIMARKETPLACE_H
#include "GuiMenu.h"
#include "ItemsManager.h"
#include "ActiveObiect.h"
#include "Places.h"
#include "Player.h"

namespace MP

{

	class GuiMarketPlace:public GuiMenu
	{
	private:

		std::unique_ptr<Obiect> panelA;

		std::unique_ptr<Obiect> panelB;

		std::unique_ptr<Item> _current_item;

		void _create_buttons(sf::Texture* buttonTexture, sf::Font& aFont);

		void _create_panels(sf::Texture* panelLeftTexture, sf::Texture* panelRightTexture);

		void _buy_item(ItemsManager& seller, ItemsManager& buyer);
	
	public:

		ItemsManager itemsSample;

		GuiMarketPlace();

		GuiMarketPlace(sf::Texture* marketplaceBackgroundTexture, sf::Texture* buttonTexture, sf::Texture* panelLeftTexture, sf::Texture* panelRightTexture, sf::Font& aFont);

		void updateMarketPlace(ActiveObiect& place,ActiveObiect &player);

		void drawMenu(sf::RenderWindow& aMainWindow,ActiveObiect& place, ActiveObiect& player);

		void selectButton(sf::Vector2f mouseCoord);

		void pressButton(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, std::shared_ptr<Player>& aPlayer, std::shared_ptr<Places>& aPlaces);
	
	};

}

#endif // !GUIMARKETPLACE_H