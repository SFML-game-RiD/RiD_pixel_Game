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
		sf::Vector2f isometric = this->_twoDToIso();
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
		case fence1Fallen:
			_flora_textures[_position_x][_position_y].setTexture(_asset_manager.getTexture("fence1Fallen"));
			_flora_textures[_position_x][_position_y].setPosition(this->_twoDToIso());
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
			_objects_textures[_position_x][_position_y].sprite.setTexture(_asset_manager.getTexture("fence1"));
			_objects_textures[_position_x][_position_y].sprite.setPosition(isometric.x + 10, isometric.y - 40);
			_objects_textures[_position_x][_position_y].size = _asset_manager.getTexture("fence1").getSize();
			_objects_textures[_position_x][_position_y].hitbox.setOutlineColor(sf::Color::Green);
			_objects_textures[_position_x][_position_y].hitbox.setOutlineThickness(1.f);
			_objects_textures[_position_x][_position_y].hitbox.setFillColor(sf::Color::Transparent);
			_objects_textures[_position_x][_position_y].hitbox.setPosition(_objects_textures[_position_x][_position_y].sprite.getPosition().x + 18.f, _objects_textures[_position_x][_position_y].sprite.getPosition().y + 68);
			_objects_textures[_position_x][_position_y].hitbox.rotate(-30);
			_objects_textures[_position_x][_position_y].hitbox.setSize(sf::Vector2f(45, 12));
			_objects_textures[_position_x][_position_y].width = _objects_textures[_position_x][_position_y].hitbox.getSize().x;
			_objects_textures[_position_x][_position_y].height = _objects_textures[_position_x][_position_y].hitbox.getSize().y;
			break;
		case sign:
			_objects_textures[_position_x][_position_y].sprite.setTexture(_asset_manager.getTexture("sign"));
			_objects_textures[_position_x][_position_y].sprite.setPosition(isometric.x + 26, isometric.y - 28);
			_objects_textures[_position_x][_position_y].size = _asset_manager.getTexture("sign").getSize();
			_objects_textures[_position_x][_position_y].hitbox.setOutlineColor(sf::Color::Green);
			_objects_textures[_position_x][_position_y].hitbox.setOutlineThickness(1.f);
			_objects_textures[_position_x][_position_y].hitbox.setFillColor(sf::Color::Transparent);
			_objects_textures[_position_x][_position_y].hitbox.setPosition(_objects_textures[_position_x][_position_y].sprite.getPosition().x + 22.f, _objects_textures[_position_x][_position_y].sprite.getPosition().y + 52);
			_objects_textures[_position_x][_position_y].hitbox.rotate(-30);
			_objects_textures[_position_x][_position_y].hitbox.setSize(sf::Vector2f(5, 5));
			break;
		case tree:
			_objects_textures[_position_x][_position_y].sprite.setTexture(_asset_manager.getTexture("tree"));
			_objects_textures[_position_x][_position_y].sprite.setPosition(isometric.x - 20, isometric.y - 120);
			_objects_textures[_position_x][_position_y].size = _asset_manager.getTexture("tree").getSize();
			_objects_textures[_position_x][_position_y].hitbox.setOutlineColor(sf::Color::Green);
			_objects_textures[_position_x][_position_y].hitbox.setOutlineThickness(1.f);
			_objects_textures[_position_x][_position_y].hitbox.setFillColor(sf::Color::Transparent);
			_objects_textures[_position_x][_position_y].hitbox.setPosition(_objects_textures[_position_x][_position_y].sprite.getPosition().x + 54.f, _objects_textures[_position_x][_position_y].sprite.getPosition().y + 134.f);
			_objects_textures[_position_x][_position_y].hitbox.setSize(sf::Vector2f(44, 18));
			break;
		case chest:
			_objects_textures[_position_x][_position_y].sprite.setTexture(_asset_manager.getTexture("chest"));
			_objects_textures[_position_x][_position_y].sprite.setPosition(isometric.x + 14, isometric.y - 30);
			_objects_textures[_position_x][_position_y].size = _asset_manager.getTexture("chest").getSize();
			_objects_textures[_position_x][_position_y].hitbox.setOutlineColor(sf::Color::Green);
			_objects_textures[_position_x][_position_y].hitbox.setOutlineThickness(1.f);
			_objects_textures[_position_x][_position_y].hitbox.setFillColor(sf::Color::Transparent);
			_objects_textures[_position_x][_position_y].hitbox.setPosition(_objects_textures[_position_x][_position_y].sprite.getPosition().x + 18, _objects_textures[_position_x][_position_y].sprite.getPosition().y + 50);
			_objects_textures[_position_x][_position_y].hitbox.setSize(sf::Vector2f(38, 18));
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
		_asset_manager.setTexture("fence1", "img/fence1.png");
		_asset_manager.setTexture("fence1Fallen", "img/fence1Fallen.png");
		_asset_manager.setTexture("sign", "img/sign.png");
		_asset_manager.setTexture("chest", "img/chest.png");
		_asset_manager.setTexture("tree", "img/tree.png");

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

		std::ofstream tiles_positions("tiles_positions.txt");//////////////

		for (unsigned int i = 0; i < _height; ++i)
		{
			for (unsigned int j = 0; j < _width; ++j)
			{
				_point.x = i * 25;
				_point.y = j * 25;
				_tile_type = _level[i][j];
				this->_placeTile(i, j);
				tiles_positions << "("<<_twoDToIso().x << "," << _twoDToIso().y<<")";

				_tile_type = _flora[i][j];
				this->_placeFlora(i, j);

				_tile_type = _objects[i][j];
				this->_placeObjects(i, j);
			}
			tiles_positions << std::endl;
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
				window.draw(_objects_textures[i][j].sprite);
				window.draw(_objects_textures[i][j].hitbox);
			}
		}
	}

	std::vector<std::vector<_obj>>& TileMap::getCollidableObjects()
	{
		return _objects_textures;
	}
}