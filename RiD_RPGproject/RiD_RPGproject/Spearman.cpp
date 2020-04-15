#include "Spearman.h"

MP::Spearman::Spearman()
{
}

MP::Spearman::Spearman(sf::Texture* texturePtr, sf::Font& aFont)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 236);
	_item_amount_text.setFont(aFont);
	setItemAmount(0);//it set text to
	_item_amount_text.setLetterSpacing(1);
	_item_amount_text.setCharacterSize(25);
	_item_amount_text.setFillColor(sf::Color(224, 224, 224));
}

void MP::Spearman::setItemAmount(unsigned int newItemAmount)
{
	std::string tmp = std::to_string(newItemAmount);

	_item_amount_text.setString(std::string("X") + tmp);
}

unsigned int& MP::Spearman::getItemAmount()
{
	return _item_amount;
}

void MP::Spearman::setItemPosition(sf::Vector2f itemPosition)
{
	setObiectCoord(itemPosition);
	itemPosition.x += 80;
	itemPosition.y += 221;
	_item_amount_text.setPosition(itemPosition);
}

void MP::Spearman::drawItem(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
	mainWindow.draw(_item_amount_text);
}
