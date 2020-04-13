#include "GuiButton.h"


MP::GuiButton::GuiButton(sf::Texture* texturePtr, sf::Vector2f buttonPosition,sf::Vector2f relativelyTextPosition, sf::Font &aFont, std::string buttonName)
{

	aAnimation.loadObiectTextures(texturePtr, 2, 1, 275);
	setObiectCoord(buttonPosition);
	_a_text.setFont(aFont);
	sf::Vector2f realTextPostion = buttonPosition;
	realTextPostion.x += 70;
	realTextPostion.y += 115;

	realTextPostion.x += relativelyTextPosition.x;
	realTextPostion.y += relativelyTextPosition.y;
	_a_text.setPosition(realTextPostion);
	_a_text.setString(buttonName);
	_a_text.setLetterSpacing(1.5);
	_a_text.setCharacterSize(30);
	_is_active = false;

}

void MP::GuiButton::setPressed()
{
}

sf::Text & MP::GuiButton::getText()
{
	return _a_text;
}

void MP::GuiButton::setButtonActive(bool isActive)
{
	if (isActive == true)
		aAnimation.changeSprite(0);
	else
		aAnimation.changeSprite(1);

	_is_active = isActive;
}

bool MP::GuiButton::getButtonActive()
{
	return _is_active;
}

void MP::GuiButton::drawButton(sf::RenderWindow& aMainWindow)
{

	aMainWindow.draw(aAnimation.getObiectSprite());
	aMainWindow.draw(_a_text);
}
