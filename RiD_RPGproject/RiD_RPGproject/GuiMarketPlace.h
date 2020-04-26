#ifndef GUIMARKETPLACE_H
#define GUIMARKETPLACE_H
#include "GuiMenu.h"
#include "ItemsManager.h"
#include "ActiveObiect.h"
#include "Places.h"
#include "Player.h"
#include "GuiPanel.h"

namespace MP

{

	class GuiMarketPlace:public GuiMenu
	{
	private:

		std::unique_ptr<GuiPanel> panelA;

		std::unique_ptr<GuiPanel> panelB;

		std::unique_ptr<Item> _current_item;

		void _create_buttons(sf::Texture* buttonTexture, sf::Font& aFont);

		void _create_panels(sf::Texture* panelLeftTexture, sf::Texture* panelRightTexture);

		void _buy_item(ItemsManager& seller, ItemsManager& buyer);
	
		void _update_market_place(Places& place,ActiveObiect &player);

		void _draw_menu(sf::RenderWindow& aMainWindow,Places& place, ActiveObiect& player);

		void _select_button(sf::Vector2f guiMouseCoord);

		void _press_button(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, std::shared_ptr<Player>& aPlayer, std::shared_ptr<Places>& aPlace);

	public:

		GuiMarketPlace();

		GuiMarketPlace(sf::Texture* marketplaceBackgroundTexture, sf::Texture* buttonTexture, sf::Texture* panelLeftTexture, sf::Texture* panelRightTexture, sf::Font& aFont);

		void update(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f guiMouseCoord, std::shared_ptr<Player>& aPlayer, std::shared_ptr<Places>& aPlace);

		void render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, std::shared_ptr<Places> aPlace ,std::shared_ptr<Player> aPlayer);
		
	};

}

#endif // !GUIMARKETPLACE_H