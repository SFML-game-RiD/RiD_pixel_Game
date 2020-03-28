#include "Map.h"
#include <iostream>
#include <fstream>

void MP::Map::_add_map_element(MapElement*& head, MapElement*& newElement)
{
	if (head == nullptr)
		head = newElement;
	else
	_add_map_element(head->getNextElement(), newElement);
}

void MP::Map::_create_web()
{
	if (_map_element_list != nullptr)
	{
		MapElement* linkingElement = _map_element_list;


		while (linkingElement != nullptr)
		{
			std::pair<int,int> tmpCoord= linkingElement->getLandTile().getObiectCoord();

			//up
			tmpCoord.second--;
			linkingElement->setUpPtr(findElementAddress(tmpCoord, _map_element_list));
			tmpCoord.second++;

			//down
			tmpCoord.second++;
			linkingElement->setDownPtr(findElementAddress(tmpCoord, _map_element_list));
			tmpCoord.second--;

			//left
			tmpCoord.first--;
			linkingElement->setLeftPtr(findElementAddress(tmpCoord, _map_element_list));
			tmpCoord.first++;

			//right
			tmpCoord.first++;
			linkingElement->setRightPtr(findElementAddress(tmpCoord, _map_element_list));
			tmpCoord.first--;

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

void MP::Map::_load_map()
{

	std::fstream mapFile;
	mapFile.open("worldmaps/worldmap1.txt", std::ios::in);

	std::string line;

	int blockLength = RiD::ConfigurationLoader::getIntData("game settings", "blockLength");
	int y = 0;

	while (mapFile)
	{
		int x = 0;
		std::getline(mapFile, line);
		
		if (mapFile)
		{
			for (int i = 0; i < line.length(); i++)
			{
				MapElement* tmp = new MapElement(x, y, line[i]);
				_add_map_element(getMapElementList(), tmp);
				x += blockLength;
			}
			y += blockLength;
		}
		}
}

MP::Map::Map()
{
	_map_element_list = nullptr;

	_load_map();

	_create_web();
}

MP::Map::~Map()
{
	_delete_map(_map_element_list);
}


MP::MapElement * MP::Map::findElementAddress(std::pair<int, int> coordinates, MapElement*& mapElementHead)
{
	if (mapElementHead == nullptr)
		return nullptr;
	else
	{

		if (mapElementHead->getLandTile().getObiectCoord().first == coordinates.first and mapElementHead->getLandTile().getObiectCoord().second == coordinates.second)
			return mapElementHead;

		findElementAddress(coordinates, mapElementHead->getNextElement());
	}
}