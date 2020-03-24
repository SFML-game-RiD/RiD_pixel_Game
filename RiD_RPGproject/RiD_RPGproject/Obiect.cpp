#include "Obiect.h"
#include "Engine/ConfigurationLoader.h"
#include <vector>

void MP::Obiect::setObiectCoord(int x, int y)
{
	animationMaker.setObiectSpritePosition(x, y);
	_objCoord.first = x;
	_objCoord.second = y;
	objSleepTime = sf::milliseconds(0);
}

std::pair<int, int> MP::Obiect::getObiectCoord()
{
	return _objCoord;
}

