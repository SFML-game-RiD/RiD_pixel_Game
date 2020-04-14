#include "Wood.h"
#include <string>
#include <iostream>

MP::Wood::Wood()
{
}

MP::Wood::Wood(sf::Texture* texturePtr,sf::Font& aFont)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 64);
	_item_amount_text.setFont(aFont);
	setItemAmount(0);//it set text to
	_item_amount_text.setLetterSpacing(1);
	_item_amount_text.setCharacterSize(25);
	_item_amount_text.setFillColor(sf::Color(224, 224, 224));
}

void MP::Wood::setItemAmount(unsigned int newItemAmount)
{
	
	std::string tmp = std::to_string(newItemAmount);

	_item_amount_text.setString(std::string("X") + tmp);
}

unsigned int& MP::Wood::getItemAmount()
{
	return _item_amount;
}

void MP::Wood::setItemPosition(sf::Vector2f itemPosition)
{
	setObiectCoord(itemPosition);
	itemPosition.x += 68;
	itemPosition.y += 30;

	_item_amount_text.setPosition(itemPosition);
}

void MP::Wood::drawItem(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
	mainWindow.draw(_item_amount_text);
}
