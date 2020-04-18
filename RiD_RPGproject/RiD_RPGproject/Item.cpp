#include "Item.h"

MP::Item::Item()
{
}

MP::Item::Item(sf::Texture* texturePtr,  sf::Font& aFont)
{
}

void MP::Item::setItemAmount(unsigned int newItemAmount)
{
}

unsigned int& MP::Item::getItemAmount()
{
	return _item_amount;
}

void MP::Item::setItemPosition(sf::Vector2f itemPosition)
{
	setObiectCoord(itemPosition);
	itemPosition.x += 68;
	itemPosition.y += 30;

	_item_amount_text.setPosition(itemPosition);

}

void MP::Item::drawItem(sf::RenderWindow& mainWindow)
{
}

void MP::Item::setTextPostion(sf::Vector2f newPosition)
{
	newPosition.x += getObiectCoord().x;
	newPosition.y += getObiectCoord().y;
	_item_amount_text.setPosition(newPosition);
}
