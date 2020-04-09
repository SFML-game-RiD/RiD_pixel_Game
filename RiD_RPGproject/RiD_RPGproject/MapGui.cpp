#include "MapGui.h"

MP::MapGui::MapGui(sf::Texture* texturePtr)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 1920);
	setObiectCoord(sf::Vector2f(0,0));
	aAnimation.setOrigin(928, 928);

}
