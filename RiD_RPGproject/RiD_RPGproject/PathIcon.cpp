#include "PathIcon.h"

MP::PathIcon::PathIcon(sf::Texture* texturePtr, sf::Vector2f spawnCoord)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 60);
	setObiectCoord(spawnCoord);
	aAnimation.setScale(0.6, 0.6);
	aAnimation.setOrigin(-29,-29);
}

void MP::PathIcon::update()
{
}

void MP::PathIcon::render(sf::RenderWindow& mainWindow)
{
}
