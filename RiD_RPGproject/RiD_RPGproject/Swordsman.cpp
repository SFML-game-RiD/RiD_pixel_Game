#include "Swordsman.h"

MP::Swordsman::Swordsman()
{
}

MP::Swordsman::Swordsman(sf::Texture* texturePtr, sf::Font& aFont)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 64);
	aAnimation.setScale(1.6, 1.60);
	_item_amount_text.setFont(aFont);
	setItemAmount(0);//it set text to
	_item_amount_text.setLetterSpacing(1);
	_item_amount_text.setCharacterSize(25);
	_item_amount_text.setFillColor(sf::Color(224, 224, 224));
}

void MP::Swordsman::setItemAmount(unsigned int newItemAmount)
{
	std::string tmp = std::to_string(newItemAmount);

	_item_amount_text.setString(std::string("X") + tmp);
}

unsigned int& MP::Swordsman::getItemAmount()
{
	return _item_amount;
}

void MP::Swordsman::setItemPosition(sf::Vector2f itemPosition)
{
	setObiectCoord(itemPosition);
	itemPosition.x += 70;
	itemPosition.y += 90;

	_item_amount_text.setPosition(itemPosition);
}

void MP::Swordsman::drawItem(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
	mainWindow.draw(_item_amount_text);
}
