#include "PawnObiect.h"

MP::PawnObiect::PawnObiect()
{
	_past_pixels = 0;
	_current_past_pixels = 0;
	_current_direction = directionNone;
}



void MP::PawnObiect::pawnAnimation()
{
	//if(_current_direction == MP::PawnObiect::direction::directionUp)

	//if(_current_direction == MP::PawnObiect::direction::directionDown)

	//if(_current_direction == MP::PawnObiect::direction::directionLeft)

//	if (_current_direction == MP::PawnObiect::direction::directionRight)
		pawnAnimationRight();
}

void MP::PawnObiect::pawnAnimationRight()
{
	_current_past_pixels = getTraveledDistance();
	
	if (_current_past_pixels > _past_pixels + 32)
	{
		s/*UseTime, No pixels!*/etNextSprite(6, 8);
	_past_pixels = _current_past_pixels;
	}
}

void MP::PawnObiect::setNextSprite(int from, int to)
{
	int currentSpriteNumber = animationMaker.getCurrentSprite();

	if (currentSpriteNumber < to)
		currentSpriteNumber++;
	else if (currentSpriteNumber == to)
		currentSpriteNumber = from;

	animationMaker.changeSprite(currentSpriteNumber);
}
