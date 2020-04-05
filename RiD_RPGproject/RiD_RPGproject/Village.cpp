#include "Village.h"

MP::Village::Village(sf::Texture* texturePtr, sf::Vector2f coord)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 64);
	setObiectCoord(coord);
}
