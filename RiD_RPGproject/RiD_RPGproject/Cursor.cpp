#include "Cursor.h"

MP::Cursor::Cursor(sf::Texture* texturePtr)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 60);
	aAnimation.setOrigin(18, 15);//Don't change it !
}
