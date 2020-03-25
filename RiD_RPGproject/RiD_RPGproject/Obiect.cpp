#include "Obiect.h"
#include "Engine/ConfigurationLoader.h"
#include <vector>

MP::Obiect::Obiect()
{
	_objCoord.first = 0;
	_objCoord.second = 0;
	_ready_animation_time = sf::milliseconds(0);
	_last_animation_active = sf::milliseconds(0);
}

void MP::Obiect::setObiectCoord(int x, int y)
{
	animationMaker.setObiectSpritePosition(x, y);
	_objCoord.first = x;
	_objCoord.second = y;
}

std::pair<int, int> MP::Obiect::getObiectCoord()
{
	return _objCoord;
}

