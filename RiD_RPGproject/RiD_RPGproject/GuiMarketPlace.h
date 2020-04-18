#ifndef GUIMARKETPLACE_H
#define GUIMARKETPLACE_H
#include "GuiMenu.h"
#include "ItemsManager.h"
#include "ActiveObiect.h"

namespace MP

{

	class GuiMarketPlace:public GuiMenu
	{
	private:

		std::unique_ptr<Obiect> panelA;

		std::unique_ptr<Obiect> panelB;

		void _create_buttons(sf::Texture* buttonTexture, sf::Font& aFont);

		void _create_panels(sf::Texture* panelLeftTexture, sf::Texture* panelRightTexture);

		void _draw_mid_items(sf::RenderWindow& mainWindow);

	
		
	public:

		ItemsManager itemsSample;

		GuiMarketPlace();

		GuiMarketPlace(sf::Texture* marketplaceBackgroundTexture, sf::Texture* buttonTexture, sf::Texture* panelLeftTexture, sf::Texture* panelRightTexture, sf::Font& aFont);

		void updateMarketPlace(ActiveObiect& place,ActiveObiect &player);

		void drawMenu(sf::RenderWindow& aMainWindow,ActiveObiect& place, ActiveObiect& player);

		void selectButton(sf::Vector2f mouseCoord);

		void pressButton(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);

		void selectItem(sf::Vector2f mouseCoord);

		void pressItem(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);
	};

}

#endif // !GUIMARKETPLACE_H