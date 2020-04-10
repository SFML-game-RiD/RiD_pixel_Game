#pragma once

#include "TileMap.h"

namespace RTB
{
	sf::Vector2f TileMap::_twoDToIso()
	{
		return sf::Vector2f(_point.x - _point.y, (_point.x + _point.y) / 2);
	}

	void TileMap::_loadFromFile(std::string map_file_name, std::string flora_file_name, std::string objects_file_name)
	{
		std::ifstream map_file(map_file_name);
		std::ifstream flora_file(flora_file_name);
		std::ifstream objects_file(objects_file_name);
		try {
			if (!map_file.is_open() || !flora_file.is_open() || !objects_file.is_open())
				throw "Could not open file";
		}
		catch (std::string& except)
		{
			std::cerr << except;
		}

		unsigned int tmp;
		std::string line;
		while (std::getline(map_file, line))
		{
			std::vector<unsigned int > row;
			std::istringstream string_stream(line);
			while (string_stream >> tmp)
			{
				row.push_back(tmp);
			}
			_level.push_back(row);
		}

		while (std::getline(flora_file, line))
		{
			std::vector<unsigned int > row;
			std::istringstream string_stream(line);
			while (string_stream >> tmp)
			{
				row.push_back(tmp);
			}
			_flora.push_back(row);
		}

		while (std::getline(objects_file, line))
		{
			std::vector<unsigned int > row;
			std::istringstream string_stream(line);
			while (string_stream >> tmp)
			{
				row.push_back(tmp);
			}
			_objects.push_back(row);
		}
		_height = _level.size();
		_width = _level[0].size();
		map_file.close();
		flora_file.close();
		objects_file.close();
	}

	void TileMap::_placeTile(unsigned short _position_x, unsigned short _position_y)
	{
		switch (_tile_type)
		{
		case dirt:
		{
			std::unique_ptr<MapElement> ptr = std::unique_ptr<MapElement>(new MapElement(_asset_manager.getTexture("dirt"), this->_twoDToIso()));
			_map_elements[_position_x][_position_y] = std::move(ptr);
			break;
		}
		case grass:
		{
			std::unique_ptr<MapElement> ptr = std::unique_ptr<MapElement>(new MapElement(_asset_manager.getTexture("grass"), this->_twoDToIso()));
			_map_elements[_position_x][_position_y] = std::move(ptr);
			break;
		}
		case water:
		{
			std::unique_ptr<MapElement> ptr = std::unique_ptr<MapElement>(new MapElement(_asset_manager.getTexture("water"), this->_twoDToIso()));
			_map_elements[_position_x][_position_y] = std::move(ptr);
			break;
		}
		case road:
		{
			std::unique_ptr<MapElement> ptr = std::unique_ptr<MapElement>(new MapElement(_asset_manager.getTexture("road"), this->_twoDToIso()));
			_map_elements[_position_x][_position_y] = std::move(ptr);
			break;
		}
		}
	}

	void TileMap::_placeFlora(unsigned short _position_x, unsigned short _position_y)
	{
		sf::Vector2f isometric = this->_twoDToIso();
		switch (_tile_type)
		{
		case no_flora:
			break;
		case tinyFlower:
			_map_elements[_position_x][_position_y]->setFlora(_asset_manager.getTexture("tinyFlowers"), this->_twoDToIso());
			break;
		case redFlower:
			_map_elements[_position_x][_position_y]->setFlora(_asset_manager.getTexture("redFlower"), this->_twoDToIso());
			break;
		case fence1Fallen:
			_map_elements[_position_x][_position_y]->setFlora(_asset_manager.getTexture("fence1Fallen"), this->_twoDToIso());
			break;
		}
	}

	void TileMap::_placeObjects(unsigned short _position_x, unsigned short _position_y)
	{
		sf::Vector2f isometric = this->_twoDToIso();
		switch (_tile_type)
		{
		case no_object:
			break;
		case fence1:
			_map_elements[_position_x][_position_y]->setObject(_asset_manager.getTexture("fence1"), { isometric.x, isometric.y }, { 15, 55 }, { 45,12 }, { 8.f, 10.f }, -30);
			break;
		case sign:
			_map_elements[_position_x][_position_y]->setObject(_asset_manager.getTexture("sign"), { isometric.x + 20 , isometric.y + 8 }, { 24, 50 }, { 5,5 }, { 0.f, 0.f }, 0);
			break;
		case tree:
			_map_elements[_position_x][_position_y]->setObject(_asset_manager.getTexture("tree"), { isometric.x, isometric.y }, { 50, 136 }, { 44,18 }, { 0.f, 0.f }, 0);
			break;
		case chest:
			_map_elements[_position_x][_position_y]->setObject(_asset_manager.getTexture("chest"), { isometric.x + 30, isometric.y + 30 }, { 42, 72 }, { 38,18 }, { -24.f, -24.f }, 0);
			break;

		}
	}

	void TileMap::_generateWalkableArea()
	{
		for (unsigned int i = 0; i < _height; i++)
		{
			for (unsigned int j = 0; j < _width; j++)
			{
				if (!_map_elements[i][j]->isWalkable())
				{
					if (i > 0 && j > 0 && j < _width-1 && i < _height-1)
					{
						unsigned short end_k = i + 1, end_l = j + 1;
						for (unsigned short k = i - 1; k <= end_k; k++)
						{
							for (unsigned short l = j - 1; l <= end_l; l++)
							{
								_walkable_area[k][l] = 1;
							}
						}
					}
					else if (i == 0 && j > 0 && j < _width-1)
					{
						for (unsigned short k = i; k <= i + 1; k++)
							for (unsigned short l = j - 1; l < j + 1; l++)
								_walkable_area[k][l] = 1;
					}
					else if (i == _height - 1 && j > 0 && j < _width-1)
					{
						for (unsigned short k = i - 1; k <= i; k++)
							for (unsigned short l = j - 1; l < j + 1; l++)
								_walkable_area[k][l] = 1;
					}
					else if (j == 0 && i > 0 && i < _height-1)
					{
						for (unsigned short k = i - 1; k <= i + 1; k++)
							for (unsigned short l = j; l < j + 1; l++)
								_walkable_area[k][l] = 1;
					}
					else if (j == _width - 1 && i > 0 && i < _height-1)
					{
						for (unsigned short k = i - 1; k < i + 1; k++)
							for (unsigned short l = j - 1; l < j; l++)
								_walkable_area[k][l] = 1;
					}
					else if (j == 0 && i == 0)
					{
						_walkable_area[0][0] = 1;
						_walkable_area[0][1] = 1;
						_walkable_area[1][0] = 1;
						_walkable_area[1][1] = 1;
					}
					else if (j == 0 && i == _height - 1)
					{
						_walkable_area[_height - 2][0] = 1;
						_walkable_area[_height - 2][1] = 1;
						_walkable_area[_height - 1][0] = 1;
						_walkable_area[_height - 1][1] = 1;
					}
					else if (j == _width - 1 && i == _height - 1)
					{
						_walkable_area[_height - 2][_width - 2] = 1;
						_walkable_area[_height - 2][_width - 1] = 1;
						_walkable_area[_height - 1][_width - 2] = 1;
						_walkable_area[_height - 1][_width - 1] = 1;
					}
					else if (j == _width - 1 && i == 0)
					{
						_walkable_area[0][_width - 1] = 1;
						_walkable_area[0][_width - 2] = 1;
						_walkable_area[1][_width - 1] = 1;
						_walkable_area[1][_width - 2] = 1;
					}
				}
			}
		}
	}

	TileMap::TileMap(sf::Vector2i tile_size)
	{
		_asset_manager.setTexture("grass", "img/grass.png");
		_asset_manager.setTexture("road", "img/road.png");
		_asset_manager.setTexture("water", "img/water.png");
		_asset_manager.setTexture("dirt", "img/dirt.png");
		_asset_manager.setTexture("tinyFlowers", "img/tinyFlowers.png");
		_asset_manager.setTexture("redFlower", "img/redFlower.png");
		_asset_manager.setTexture("fence1", "img/fence1.png");
		_asset_manager.setTexture("fence1Fallen", "img/fence1Fallen.png");
		_asset_manager.setTexture("sign", "img/sign.png");
		_asset_manager.setTexture("chest", "img/chest.png");
		_asset_manager.setTexture("tree", "img/tree.png");

		this->_loadFromFile("Map/map.txt", "Map/mapFlora.txt", "Map/mapObjects.txt");

		_map_elements.resize(_height);
		for (unsigned int i = 0; i < _height; ++i)
			_map_elements[i].resize(_width);

		_walkable_area.resize(_height);
		for (unsigned int i = 0; i < _height; ++i)
			_walkable_area[i].resize(_width);
		
		for (unsigned int i = 0; i < _height; ++i)
		{
			for (unsigned int j = 0; j < _width; ++j)
			{
				_point.x = i * 25;
				_point.y = j * 25;
				_tile_type = _level[i][j];
				this->_placeTile(i, j);

				_tile_type = _flora[i][j];
				this->_placeFlora(i, j);

				_tile_type = _objects[i][j];
				this->_placeObjects(i, j);
			}
		}
		this->_generateWalkableArea();
	}


	void TileMap::drawTiles(sf::RenderTarget& window)
	{
		for (unsigned short i = 0; i < _height; ++i)
		{
			for (unsigned short j = 0; j < _width; ++j)
			{
				window.draw(_map_elements[i][j]->getGround());
				if (!_map_elements[i][j]->isFloraNull())
					window.draw(_map_elements[i][j]->getFlora());
			}
		}
	}
	void TileMap::drawObjects(sf::RenderTarget& window)
	{
		for (unsigned short i = 0; i < _height; ++i)
		{
			for (unsigned short j = 0; j < _width; ++j)
			{
				if (!_map_elements[i][j]->isObjectNull())
				{
					window.draw(_map_elements[i][j]->getObjects());
					window.draw(_map_elements[i][j]->getObjectsHitbox());
				}
			}
		}
	}

	std::vector<std::vector<std::unique_ptr<MapElement>>>& TileMap::getCollidableObjects()
	{
		return _map_elements;
	}

	unsigned short& TileMap::getWidth()
	{
		return _width;
	}

	unsigned short& TileMap::getHeight()
	{
		return _height;
	}

	sf::Vector2f TileMap::_twoDToIso(sf::Vector2f position)
	{
		return sf::Vector2f(position.x - position.y, (position.x + position.y) / 2);
	}

}