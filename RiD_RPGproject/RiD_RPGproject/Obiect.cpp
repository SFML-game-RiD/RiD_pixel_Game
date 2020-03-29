#include "Obiect.h"
#include "Engine/ConfigurationLoader.h"
#include <vector>

MP::Obiect::Obiect()
{
	//_objCoord.first = 0;
	//_objCoord.second = 0;
		_objCoord.x = 0;
	_objCoord.y = 0;
	_ready_animation_time = sf::milliseconds(0);
	_last_animation_active = sf::milliseconds(0);
}

void MP::Obiect::setObiectCoord(int x, int y)
{
	animationMaker.setObiectSpritePosition(x, y);
	//_objCoord.first = x;
	//_objCoord.second = y;
	_objCoord.x = x;
	_objCoord.y = y;
}

void MP::Obiect::setObiectCoord(/*std::pair<int, int> coord*/ sf::Vector2f coord)
{
	animationMaker.setObiectSpritePosition(coord);
	_objCoord = coord;
}

/*std::pair<int, int> */ sf::Vector2f  MP::Obiect::getObiectCoord()
{
	return _objCoord;
}

void MP::Obiect::setLastActiveAnimation(sf::Clock currentTime)
{
	_ready_animation_time = _last_animation_active = currentTime.getElapsedTime();
	_ready_animation_time += obj_animation_sleep_time;
}