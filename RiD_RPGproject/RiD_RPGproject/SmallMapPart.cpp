#include "SmallMapPart.h"

MP::SmallMapPart::SmallMapPart(sf::Vector2f smallMapCoord, bool isWalkable)
{
	coord = smallMapCoord;
	//_up_element = nullptr;
	//_down_element = nullptr;
	//_left_element= nullptr;
	//_right_element= nullptr;
	_next_element = nullptr;
	_walkable = isWalkable;
}

sf::Vector2f MP::SmallMapPart::getSmallPartCoord()
{
	return coord;
}

void MP::SmallMapPart::setNextPtr(std::shared_ptr<MP::SmallMapPart> aMapElement)
{
	_next_element = aMapElement;
}
bool MP::SmallMapPart::isWalkable()
{
	return _walkable;
}

//void MP::SmallMapPart::setUpPtr(std::shared_ptr<MP::SmallMapPart> aMapElement)
//{
//	_up_element = aMapElement;
//}
//
//void MP::SmallMapPart::setDownPtr(std::shared_ptr<MP::SmallMapPart> aMapElement)
//{
//	_down_element = aMapElement;
//}
//
//void MP::SmallMapPart::setLeftPtr(std::shared_ptr<MP::SmallMapPart> aMapElement)
//{
//	_left_element = aMapElement;
//}
//
//void MP::SmallMapPart::setRightPtr(std::shared_ptr<MP::SmallMapPart> aMapElement)
//{
//	_right_element = aMapElement;
//}

std::shared_ptr<MP::SmallMapPart> MP::SmallMapPart::getNextElement()
{
	return _next_element;
}
//
//std::shared_ptr<MP::SmallMapPart> MP::SmallMapPart::getUpPtrCopy()
//{
//	return _up_element;
//}
//
//std::shared_ptr<MP::SmallMapPart> MP::SmallMapPart::getDownPtrCopy()
//{
//	return _down_element;
//}
//
//std::shared_ptr<MP::SmallMapPart> MP::SmallMapPart::getLeftPtrCopy()
//{
//	return _left_element;
//}
//
//std::shared_ptr<MP::SmallMapPart> MP::SmallMapPart::getRightPtrCopy()
//{
//	return _right_element;
//}
