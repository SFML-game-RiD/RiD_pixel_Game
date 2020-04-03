#include "PawnObiect.h"

bool MP::PawnObiect::checkGoUp(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.y -= _block_length;
	MapElement* tmp2= aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
		return true;
	else
		return false;
}

bool MP::PawnObiect::checkGoDown(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.y += _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
		return true;
	else
		return false;
}

bool MP::PawnObiect::checkGoLeft(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.x -= _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
		return true;
	else
		return false;
}

bool MP::PawnObiect::checkGoRight(MP::Map& aMap)
{
	sf::Vector2f tmp = getObiectCoord();
	tmp.x += _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp, aMap.getMapElementList());
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
		return true;
	else
		return false;
}
