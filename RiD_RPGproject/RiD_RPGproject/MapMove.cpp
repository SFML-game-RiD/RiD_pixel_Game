#include "MapMove.h"

void MP::MapMove::moveOnePixelLeft(ActiveObiect obiect)
{
	obiect.objSprite.move(0, 1);
}

void MP::MapMove::moveOnePixelRight(ActiveObiect obiect)
{
	obiect.objSprite.move(0, -1);
}

void MP::MapMove::moveOnePixelUp(ActiveObiect obiect)
{
	obiect.objSprite.move(1, 0);
}

void MP::MapMove::moveOnePixelDown(ActiveObiect obiect)
{
	obiect.objSprite.move(-1, 0);
	
}
