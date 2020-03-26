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
		int columnsCounter = 0;
		std::getline(mapFile, line);
		while (columnsCounter != line.length())
		{
			MapElement* tmp = new MapElement(y, x, line[columnsCounter]);
			_add_map_element(getMapElementList(), tmp);
			x += blockLength;
			columnsCounter++;
		}
		y += blockLength;
	}
}

MP::Map::Map()
{
	_map_element_list = nullptr;

	_load_map();
}

MP::Map::~Map()
{
	_delete_map(_map_element_list);
}
