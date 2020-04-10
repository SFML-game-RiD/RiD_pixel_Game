#include "Cursor.h"

void MP::Cursor::saveGuiCoord(sf::Vector2f guiCoord)
{
	_gui_coord = guiCoord;
}

sf::Vector2f MP::Cursor::getGuiCoord()
{
	return _gui_coord;
}

MP::Cursor::Cursor(sf::Texture* texturePtr)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 60);
	aAnimation.setOrigin(18, 15);//Don't change it !
}
