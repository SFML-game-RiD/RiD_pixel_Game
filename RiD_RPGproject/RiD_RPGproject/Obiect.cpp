#include "Obiect.h"
#include "Engine/ConfigurationLoader.h"

void MP::Obiect::setObiectCoord(int x, int y)
{
	objSprite.setPosition(x, y);
	_objCoord.first = x;
	_objCoord.second = y;
	objSleepTime = sf::milliseconds(RiD::ConfigurationLoader::getIntData("player", "sleepTime"));
}

std::pair<int, int> MP::Obiect::getObiectCoord()
{
	return _objCoord;
}
