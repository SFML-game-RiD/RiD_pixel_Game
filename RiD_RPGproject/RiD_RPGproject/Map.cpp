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
	_walkable_map_element_count = 0;
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
	int counter = _random_value() % _walkable_map_element_count;
	MapElement* tmp = _map_element_list;

	while (counter != 0 and tmp!=nullptr)
	{
		if (tmp->isWalkable())
		{
			counter--;
			if (counter == 0)
				return tmp;
		}
		tmp = tmp->getNextElement();
	}

	return nullptr;
}

int& MP::Map::getWalkableCounter()
{
	return _walkable_map_element_count;
}
