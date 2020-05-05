#include "GuiButton.h"


MP::GuiButton::GuiButton(sf::Texture* texturePtr, sf::Vector2f buttonPosition,sf::Vector2f relativelyTextPosition, sf::Font &aFont, std::string buttonName)
{

	aAnimation.loadObjectTextures(texturePtr, 2, 1, 275);
	setObjectCoord(buttonPosition);
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

sf::Text & MP::GuiButton::getText()
{
	return _a_text;
}

void MP::GuiButton::set_button_active(bool isActive)
{
	if (isActive == true)
		aAnimation.changeSprite(0);
	else
		aAnimation.changeSprite(1);

	_is_active = isActive;
}

bool MP::GuiButton::getButtonIsActive()
{
	return _is_active;
}

void MP::GuiButton::draw_button(sf::RenderWindow& aMainWindow)
{

	aMainWindow.draw(aAnimation.getObjectSprite());
	aMainWindow.draw(_a_text);
}

void MP::GuiButton::setButtonPosition(sf::Vector2f newPostion)
{	
	sf::Vector2f oldTextPosition =_a_text.getPosition();
	sf::Vector2f oldObjCoord = getObjectCoord();

	setObjectCoord(newPostion);

	newPostion.x+= oldTextPosition.x - oldObjCoord.x;
	newPostion.y+= oldTextPosition.y - oldObjCoord.y;

	_a_text.setPosition(newPostion);
}

void MP::GuiButton::update(bool isActive)
{
	set_button_active(isActive);
}

void MP::GuiButton::render(sf::RenderWindow& aMainWindow)
{
	draw_button(aMainWindow);
}
