#include "Places.h"

MP::Places::Places()
{
}

MP::ItemsManager& MP::Places::getItemsForTrade()
{
	return itemsForTrade;
}

void MP::Places::update()
{
}

void MP::Places::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
}
