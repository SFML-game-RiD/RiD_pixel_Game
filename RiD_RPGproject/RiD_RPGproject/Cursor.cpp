#include "Cursor.h"

void MP::Cursor::saveGameCoord(sf::Vector2f guiCoord)
{
	_game_coord = guiCoord;
}

sf::Vector2f MP::Cursor::getGuiCoord()
{
	return _game_coord;
}

MP::Cursor::Cursor(sf::Texture* texturePtr)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 60);
	aAnimation.setOrigin(18, 15);//Don't change it !
}
