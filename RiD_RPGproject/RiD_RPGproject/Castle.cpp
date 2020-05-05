#include "Castle.h"

MP::Castle::Castle(sf::Texture* texturePtr, sf::Vector2f coord)
{
	aAnimation.loadObjectTextures(texturePtr, 1, 1, 64);
	setObjectCoord(coord);
}
