#include "Obiect.h"
#include "Engine/ConfigurationLoader.h"

MP::Obiect::Obiect()
{
	_objCoord.x = 0;
	_objCoord.y = 0;
	_ready_animation_time = sf::milliseconds(0);
	_last_animation_active = sf::milliseconds(0);
}

void MP::Obiect::setObiectCoord(int x, int y)
{
	aAnimation.setObiectSpritePosition(x, y);

	_objCoord.x = float(x);
	_objCoord.y = float(y);
}

void MP::Obiect::setObiectCoord(sf::Vector2f coord)
{
	aAnimation.setObiectSpritePosition(coord);
	_objCoord = coord;
}

sf::Vector2f  MP::Obiect::getObiectCoord()
{
	return _objCoord;
}

void MP::Obiect::setLastActiveAnimation(sf::Clock currentTime)
{
	_ready_animation_time = _last_animation_active = currentTime.getElapsedTime();
	_ready_animation_time += _obj_animation_sleep_time;
}

//void MP::Obiect::update()
//{
//}
//
//void MP::Obiect::render()
//{
//}
