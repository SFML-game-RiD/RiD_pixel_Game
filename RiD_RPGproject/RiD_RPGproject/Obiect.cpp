#include "Obiect.h"

void MP::Obiect::setObiectCoord(int x, int y)
{
	objSprite.setPosition(x, y);
	_objCoord.first = x;
	_objCoord.second = y;
}

std::pair<int, int> MP::Obiect::getObiectCoord()
{
	return _objCoord;
}
