#include "Land.h"

MP::Land::Land(sf::Texture* texturePtr, int x, int y)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 64);

	setObiectCoord(x, y);
}

MP::Land::Land(int x, int y)
{
	setObiectCoord(x, y);
}

void MP::Land::update()
{
}

void MP::Land::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObiectSprite());
}
 