#include "Archer.h"

MP::Archer::Archer()
{
}

MP::Archer::Archer(sf::Texture* texturePtr, sf::Font& aFont)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 64);
	aAnimation.setScale(1.5, 1.5);
	_item_amount_text.setFont(aFont);
	setItemAmount(0);//it set text to
	_item_amount_text.setLetterSpacing(1);
	_item_amount_text.setCharacterSize(40);
}

void MP::Archer::setItemAmount(unsigned int newItemAmount)
{
	std::string tmp = std::to_string(newItemAmount);

	_item_amount_text.setString(std::string("X") + tmp);
}

unsigned int& MP::Archer::getItemAmount()
{
	return _item_amount;
}

void MP::Archer::setItemPosition(sf::Vector2f itemPosition)
{
	setObiectCoord(itemPosition);
	_item_amount_text.setPosition(itemPosition);
}

void MP::Archer::drawItem(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
	mainWindow.draw(_item_amount_text);
}
