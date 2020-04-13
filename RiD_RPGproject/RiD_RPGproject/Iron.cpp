#include "Iron.h"

MP::Iron::Iron()
{
}

MP::Iron::Iron(sf::Texture* texturePtr, sf::Font& aFont)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 64);
	_item_amount_text.setFont(aFont);
	setItemAmount(0);//it set text to
	_item_amount_text.setLetterSpacing(1);
	_item_amount_text.setCharacterSize(40);
}

void MP::Iron::setItemAmount(unsigned int newItemAmount)
{
	std::string tmp = std::to_string(newItemAmount);

	_item_amount_text.setString(std::string("X") + tmp);
}

unsigned int& MP::Iron::getItemAmount()
{
	return _item_amount;
}

void MP::Iron::setItemPosition(sf::Vector2f itemPosition)
{
	setObiectCoord(itemPosition);
	_item_amount_text.setPosition(itemPosition);
}

void MP::Iron::drawItem(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
	mainWindow.draw(_item_amount_text);
}
