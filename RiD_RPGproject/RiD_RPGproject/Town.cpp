#include "Town.h"

MP::Town::Town(sf::Texture* texturePtr, sf::Vector2f coord)
{
	animationMaker.loadObiectTextures(texturePtr, 1, 1, 64);
	setObiectCoord(coord);
}
