#include "Castle.h"

MP::Castle::Castle(sf::Texture* texturePtr, sf::Vector2f coord)
{
	//animationMaker.loadObiectTextures("img/mpimg/places/mpcastle.png", 1, 1, 64);
	animationMaker.loadObiectTextures(texturePtr, 1, 1, 64);
	setObiectCoord(coord);
}
