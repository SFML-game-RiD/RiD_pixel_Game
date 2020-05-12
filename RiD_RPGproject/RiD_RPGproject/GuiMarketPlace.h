#pragma once
#include "GuiMenu.h"
#include "ItemsManager.h"
#include "ActiveObject.h"
#include "Places.h"
#include "Player.h"
#include "GuiPanel.h"

namespace MP

{

	class GuiMarketPlace:public GuiMenu
	{
	private:

		std::shared_ptr<Places> _current_place;///Stores current places, which trade with player.

		std::unique_ptr<GuiPanel> _panelA;///Stores panelA.

		std::unique_ptr<GuiPanel> _panelB;///Stores PanelB.

		std::unique_ptr<Item> _current_item;///Stores current item used in trade.

		//Creates buttons.
		//@param aAssetManager contains textures and fonts.
		void _create_buttons(RiD::AssetManager& aAssetManager);

		//Creates panels.
		//@param panelLefttexture panel's texture.
		//@param panelRighttexture panel's texture.
		void _create_panels(sf::Texture* panelLeftTexture, sf::Texture* panelRightTexture);

		//Trades current item.
		//@param seller sells item.
		//@param buyer buys item.
		void _buy_item(ItemsManager& seller, ItemsManager& buyer);
		
		//Updates market place.
		//@param place trades object.
		//@param player trades object.
		void _update_market_place(Places& place, ActiveObject& player);

		//Updates market place.
		//@param aMainWindow main game's window.
		//@param place trades object.
		//@param player trades object.
		void _draw_menu(sf::RenderWindow& aMainWindow,Places& place, ActiveObject& player);

		//Checks mouse coordinates and makes button active.
		//@param mouseCoord mouse's coordinates.
		void _select_button(SoundManager& aSoundManager, TaskManager& aTaskManager, sf::Vector2f guiMouseCoord);

		//Starts procedures relative to pressed button.
		//@param aMainTaskManager main task manager.
		//@param aMainWindow game's main window.
		void _press_button(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, std::shared_ptr<Player>& aPlayer, std::shared_ptr<Places>& aPlace);

	public:

		//GUI market place constructor.
		GuiMarketPlace();

		//GUI market place constructor.
		//@param marketplaceBackgroundTexture background's texture.
		//@param buttonTexture button's texture.
		//@param panelLeftTexture panel's texture.
		//@param panelRightTexture panel's texture.
		//@param aFont game's font.
	//	GuiMarketPlace(sf::Texture* marketplaceBackgroundTexture, sf::Texture* buttonTexture, sf::Texture* panelLeftTexture, sf::Texture* panelRightTexture, sf::Font& aFont);
		GuiMarketPlace(RiD::AssetManager &aAssetManager);
	
		//Updates market place.
		//@param aMainTaskManager main task manager.
		//@param aMainWindow game's window.
		//@param mouseCoord mouse's coordinates.
		//@param aPlayer store's player.
		//@param aPlace store's place.
		void update(SoundManager& aSoundManager,TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f guiMouseCoord, std::shared_ptr<Player>& aPlayer, std::shared_ptr<Places>& aPlace);

		//Draws market place.
		//@param aMainTaskManager main task manager.
		//@param aMainWindow game's window.
		//@param aPlayer store's player.
		//@param aPlace store's place.
		void render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, std::shared_ptr<Places> aPlace ,std::shared_ptr<Player> aPlayer);
		
		//Sets current place.
		//@param currentPlace current place which trades with player.
		void setCurrentPlace(std::shared_ptr<Places>& currentPlace);
	};

}