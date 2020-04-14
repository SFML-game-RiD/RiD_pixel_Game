#include "MapGui.h"

MP::MapGui::MapGui(sf::Texture* texturePtr)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 1920);
	setObiectCoord(sf::Vector2f(0,0));
	//aAnimation.setOrigin(928, 928);
	aAnimation.setOrigin(460, 460);
	

}

void MP::MapGui::updateItems(ItemsManager& aItemsManager)
{
	aItemsManager.getWood()->setItemPosition(sf::Vector2f(1100, 25));
	aItemsManager.getIron()->setItemPosition(sf::Vector2f(1300, 25));
	aItemsManager.getGold()->setItemPosition(sf::Vector2f(1100, 200));
	aItemsManager.getFood()->setItemPosition(sf::Vector2f(1300, 200));
	aItemsManager.getArcher()->setItemPosition(sf::Vector2f(1100, 410));
	aItemsManager.getSwordsman()->setItemPosition(sf::Vector2f(1200, 410));
	aItemsManager.getSpearman()->setItemPosition(sf::Vector2f(1300, 400));
}

void MP::MapGui::drawMapGui(sf::RenderWindow& mainWindow, ItemsManager& aItemsManager)
{
	mainWindow.draw(aAnimation.getObiectSprite());
	_draw_items(mainWindow, aItemsManager);
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
