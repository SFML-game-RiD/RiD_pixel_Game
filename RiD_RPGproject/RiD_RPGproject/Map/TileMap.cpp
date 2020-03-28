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
			if (!map_file.is_open() || !flora_file.is_open() ||!objects_file.is_open())
				throw "Could not open file";
		}
		catch (std::string& except)
		{
			std::cerr << except;
		}

		unsigned int tmp;
		std::string line;
		while(std::getline(map_file, line))
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
			_level_textures[_position_x][_position_y].setTexture(_asset_manager.getTexture("dirt"));
			_level_textures[_position_x][_position_y].setPosition(this->_twoDToIso());
			break;
		case grass:
			_level_textures[_position_x][_position_y].setTexture(_asset_manager.getTexture("grass"));
			_level_textures[_position_x][_position_y].setPosition(this->_twoDToIso());
			break;
		case water:
			_level_textures[_position_x][_position_y].setTexture(_asset_manager.getTexture("water"));
			_level_textures[_position_x][_position_y].setPosition(this->_twoDToIso());
			break;
		case road:
			_level_textures[_position_x][_position_y].setTexture(_asset_manager.getTexture("road"));
			_level_textures[_position_x][_position_y].setPosition(this->_twoDToIso());
			break;
		}
	}

	void TileMap::_placeFlora(unsigned short _position_x, unsigned short _position_y)
	{
		switch (_tile_type)
		{
		case no_flora:
			break;
		case tinyFlower:
			_flora_textures[_position_x][_position_y].setTexture(_asset_manager.getTexture("tinyFlowers"));
			_flora_textures[_position_x][_position_y].setPosition(this->_twoDToIso());
			break;
		case redFlower:
			_flora_textures[_position_x][_position_y].setTexture(_asset_manager.getTexture("redFlower"));
			_flora_textures[_position_x][_position_y].setPosition(this->_twoDToIso());
			break;
		}
	}

	void TileMap::_placeObjects(unsigned short _position_x, unsigned short _position_y)
	{
		switch (_tile_type)
		{
		case no_object:
			break;
		case fence:
			_objects_textures[_position_x][_position_y].setTexture(_asset_manager.getTexture("fence"));
			_objects_textures[_position_x][_position_y].setPosition(this->_twoDToIso());
			break;
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
		_asset_manager.setTexture("fence", "img/fence.png");

		this->_loadFromFile("Map/map.txt", "Map/mapFlora.txt", "Map/mapObjects.txt");

		_level_textures.resize(_height);
		for (unsigned int i = 0; i < _height; ++i)
			_level_textures[i].resize(_width);

		_flora_textures.resize(_height);
		for (unsigned int i = 0; i < _height; ++i)
			_flora_textures[i].resize(_width);

		_objects_textures.resize(_height);
		for (unsigned int i = 0; i < _height; ++i)
			_objects_textures[i].resize(_width);

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

				_point.x = i * 30;
				_point.y = j * 24;
				_tile_type = _objects[i][j];
				this->_placeObjects(i, j);
			}
		}
	}


	void TileMap::drawTiles(sf::RenderTarget& window)
	{
		for (unsigned short i = 0; i < _height; ++i)
		{
			for (unsigned short j = 0; j < _width; ++j)
			{
				window.draw(_level_textures[i][j]);
				window.draw(_flora_textures[i][j]);
			}
		}
	}
	void TileMap::drawObjects(sf::RenderTarget& window)
	{
		for (unsigned short i = 0; i < _height; ++i)
		{
			for (unsigned short j = 0; j < _width; ++j)
			{
				window.draw(_objects_textures[i][j]);
			}
		}
	}
}