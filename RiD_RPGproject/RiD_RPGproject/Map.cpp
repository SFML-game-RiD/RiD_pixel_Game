#include "Map.h"
#include <iostream>
#include <fstream>

void MP::Map::addMapElement(MapElement*& head, MapElement*& newElement)
{
	

	if (head == nullptr)
		head = newElement;
	else
	addMapElement(head->getNextElement(), newElement);
}

void MP::Map::createWeb()
{
	if (_map_element_list != nullptr)
	{
		MapElement* linkingElement = _map_element_list;


		while (linkingElement != nullptr)
		{
			sf::Vector2f tmpCoord= linkingElement->getLandTile().getObiectCoord();

			//up
			tmpCoord.y-=_block_length;
			linkingElement->setUpPtr(findElementAddress(tmpCoord, _map_element_list));
			tmpCoord.y+= _block_length;

			//down
			tmpCoord.y+= _block_length;
			linkingElement->setDownPtr(findElementAddress(tmpCoord, _map_element_list));
			tmpCoord.y-= _block_length;

			//left
			tmpCoord.x-= _block_length;
			linkingElement->setLeftPtr(findElementAddress(tmpCoord, _map_element_list));
			tmpCoord.x+= _block_length;

			//right
			tmpCoord.x+= _block_length;
			linkingElement->setRightPtr(findElementAddress(tmpCoord, _map_element_list));
			tmpCoord.x-= _block_length;

			linkingElement = linkingElement->getNextElement();
		}
	}
}

MP::MapElement*& MP::Map::getMapElementList()
{
	return _map_element_list;
}

void MP::Map::_delete_map(MapElement*& head)
{
	if (head == nullptr)
		return;
	else 
	{
		_delete_map(head->getNextElement());

		delete head;
	}
}


MP::Map::Map()
{
	_random_value.seed(time(0));
	_map_element_list = nullptr;
	_block_length = RiD::ConfigurationLoader::getIntData("game settings", "blockLength");
}

MP::Map::~Map()
{
	_delete_map(_map_element_list);
}


MP::MapElement * MP::Map::findElementAddress(sf::Vector2f coordinates, MapElement*& mapElementHead)
{
	if (mapElementHead == nullptr)
		return nullptr;
	else
	{
		if (mapElementHead->getLandTile().getObiectCoord().x == coordinates.x and mapElementHead->getLandTile().getObiectCoord().y == coordinates.y)
			return mapElementHead;

		findElementAddress(coordinates, mapElementHead->getNextElement());
	}
}

MP::MapElement* MP::Map::findElementAddressSquareRange(sf::Vector2f coordinates, MapElement*& mapElementHead)
{
	if (mapElementHead == nullptr)
		return nullptr;
	else
	{
		if (mapElementHead == nullptr)
			mapElementHead = nullptr;
		if (coordinates.x <= mapElementHead->getLandTile().getObiectCoord().x+_block_length and
			coordinates.y <= mapElementHead->getLandTile().getObiectCoord().y + _block_length )
			return mapElementHead;

		findElementAddressSquareRange(coordinates, mapElementHead->getNextElement());
	}
}

void MP::Map::copyMapElementList(MapElement* aMapElementList)
{
	_map_element_list = aMapElementList;
}

MP::MapElement* MP::Map::returnRandomWalkableElement()
{

	MapElement* tmp=nullptr;
	sf::Vector2f randVector;
	randVector.x = _random_value() % _last_element_coord.x;
	randVector.y = _random_value() % _last_element_coord.y;

	tmp = findElementAddressSquareRange(randVector, _map_element_list);

	while (tmp->isWalkable() ==false)
	{
		randVector.x = _random_value() % _last_element_coord.x;
		randVector.y = _random_value() % _last_element_coord.y;
	tmp=findElementAddressSquareRange(randVector, _map_element_list);
	if (tmp == nullptr)
		tmp = nullptr;
	}
	return tmp;
}

void MP::Map::setLastElementCoord(sf::Vector2f aVector)
{
	_last_element_coord.x = aVector.x;
	_last_element_coord.y = aVector.y;
}