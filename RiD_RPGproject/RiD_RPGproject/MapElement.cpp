#include "MapElement.h"

MP::Land & MP::MapElement::getLandTile()
{
	return *std::dynamic_pointer_cast<Land>(_land_tile);;
}

MP::MapElement::MapElement(int cordX, int cordY, char mark)
{
	_up_element = nullptr;
	_down_element = nullptr;
	_left_element = nullptr;
	_right_element = nullptr;

	_next_element = nullptr;

	_land_tile = std::make_shared<MP::Land>(cordX, cordY, mark);
}

MP::MapElement*& MP::MapElement::getNextElement()
{
	return _next_element;
}

MP::MapElement*& MP::MapElement::getUpPtr()
{
	return _up_element;
}

MP::MapElement*& MP::MapElement::getDownPtr()
{
	return _down_element;
}

MP::MapElement*& MP::MapElement::getLeftPtr()
{
	return _left_element;
}

MP::MapElement*& MP::MapElement::getRightPtr()
{
	return _right_element;
}
