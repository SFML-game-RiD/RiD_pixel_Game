#pragma once

#include "SFML/Graphics.hpp"
#include "../Engine/AssetManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

namespace RTB
{
	class TileMap
	{
	private:
		RiD::AssetManager _asset_manager;
		enum _tiles {dirt, grass, water, road};
		enum _flora {no_flora, tinyFlower, redFlower};
		enum _objects {no_object, fence};

		std::vector<std::vector<unsigned int>> _level;
		std::vector<std::vector<sf::Sprite>> _level_textures;

		std::vector<std::vector<unsigned int>> _flora;
		std::vector<std::vector<sf::Sprite>> _flora_textures;

		std::vector<std::vector<unsigned int>> _objects;
		std::vector<std::vector<sf::Sprite>> _objects_textures;

		unsigned short _width , _height , _tile_type;
		sf::Vector2i _point;

		sf::Vector2f _twoDToIso();
		void _loadFromFile(std::string map_file_name, std::string flora_file_name, std::string objects_file_name);
		void _placeTile(unsigned short _position_x, unsigned short _position_y);
		void _placeFlora(unsigned short _position_x, unsigned short _position_y);
		void _placeObjects(unsigned short _position_x, unsigned short _position_y);
	public:
		TileMap(sf::Vector2i tile_size);

		void drawTiles(sf::RenderTarget& window);

		void drawObjects(sf::RenderTarget& window);
	};
}