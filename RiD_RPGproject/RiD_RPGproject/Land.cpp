#include "Land.h"

MP::Land::Land(sf::Texture* texturePtr, int x, int y)
{
	animationMaker.loadObiectTextures(texturePtr, 1, 1, 64);

	setObiectCoord(x, y);
}
 