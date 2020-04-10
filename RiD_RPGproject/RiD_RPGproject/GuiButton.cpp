#include "GuiButton.h"


MP::GuiButton::GuiButton(sf::Texture* texturePtr, sf::Vector2f buttonPosition)
{

	aAnimation.loadObiectTextures(texturePtr, 1, 2, 275);
	setObiectCoord(buttonPosition);
}

void MP::GuiButton::setPressed()
{
}
