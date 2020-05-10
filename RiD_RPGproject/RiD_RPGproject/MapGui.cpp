#include "MapGui.h"

MP::MapGui::MapGui(RiD::AssetManager& aAssetManager)
{
	aAnimation.loadObjectTextures(&aAssetManager.getTexture("mapgui"), 1, 1, 1920);
	setObjectCoord(sf::Vector2f(0,0));
	aAnimation.setOrigin(460, 460);
	

}

void MP::MapGui::_update_items(ItemsManager& aItemsManager)
{
	aItemsManager.getWood()->setItemPosition(sf::Vector2f(1100, 25));
	aItemsManager.getIron()->setItemPosition(sf::Vector2f(1300, 25));
	aItemsManager.getGold()->setItemPosition(sf::Vector2f(1100, 100));
	aItemsManager.getFood()->setItemPosition(sf::Vector2f(1300, 100));


	aItemsManager.getArcher()->setItemPosition(sf::Vector2f(1040, 310));
	aItemsManager.getArcher()->aAnimation.setScale(1, 1);

	aItemsManager.getSwordsman()->setItemPosition(sf::Vector2f(1155, 310));
	aItemsManager.getSwordsman()->aAnimation.setScale(1, 1);

	aItemsManager.getSpearman()->setItemPosition(sf::Vector2f(1250, 290));
	aItemsManager.getSpearman()->aAnimation.setScale(1, 1);

}

void MP::MapGui::render(sf::RenderWindow& mainWindow, ItemsManager& aItemsManager)
{
	mainWindow.draw(aAnimation.getObjectSprite());
	_draw_items(mainWindow, aItemsManager);
}

void MP::MapGui::update(ItemsManager& aItemsManager)
{
	_update_items(aItemsManager);
}

void MP::MapGui::_draw_items(sf::RenderWindow& mainWindow, ItemsManager& aItemsManager)
{
	aItemsManager.getWood()->drawItem(mainWindow);
	aItemsManager.getIron()->drawItem(mainWindow);
	aItemsManager.getGold()->drawItem(mainWindow);
	aItemsManager.getFood()->drawItem(mainWindow); 
	aItemsManager.getArcher()->drawItem(mainWindow);
	aItemsManager.getSwordsman()->drawItem(mainWindow);
	aItemsManager.getSpearman()->drawItem(mainWindow);
}
