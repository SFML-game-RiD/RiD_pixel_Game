#include "MapAnimation.h"

void  MP::MapAnimation::_get_rectangle_array(int columns, int rows, int squareLength)
{
	int x = 0, y = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sf::IntRect tmp(y, x, squareLength, squareLength);

			_obiect_rectangle_array.push_back(tmp);

			y += squareLength;
		}
		x += squareLength;
		y = 0;
	}
}

void MP::MapAnimation::setObiectSpritePosition(int x, int y)
{
	_obj_sprite.setPosition(x, y);
}

void MP::MapAnimation::setObiectSpritePosition(std::pair<int, int> coord)
{
	_obj_sprite.setPosition(coord.first, coord.second);
}

sf::Sprite& MP::MapAnimation::getObiectSprite()
{
	return _obj_sprite;
}

void MP::MapAnimation::loadObiectTextures(std::string texturePath, int columns, int rows, int squareLength)
{
	_obj_texture.loadFromFile(texturePath);
	_set_obiect_texture(_obj_texture);
	_get_rectangle_array(columns, rows, squareLength);
	changeSprite(0);
}

void MP::MapAnimation::_set_obiect_texture(sf::Texture &texture)
{
	_obj_sprite.setTexture(texture);
}

void MP::MapAnimation::_set_obiect_texture_rect(sf::IntRect &textureRect)
{
	_obj_sprite.setTextureRect(textureRect);
}

void MP::MapAnimation::changeSprite(int spriteNumber)
{
	_set_obiect_texture_rect(_obiect_rectangle_array[spriteNumber]);
	_current_sprite = spriteNumber;
}

const std::vector<sf::IntRect>& MP::MapAnimation::getOryginalArray()
{
	return _obiect_rectangle_array;
}

int MP::MapAnimation::getCurrentSprite()
{
	return _current_sprite;
}

void MP::MapAnimation::setNextSprite(int from, int to)
{
	int currentSpriteNumber = getCurrentSprite();

	if (currentSpriteNumber < to and currentSpriteNumber >=from)
		currentSpriteNumber++;
	else if (currentSpriteNumber == to)
		currentSpriteNumber = from;
	else if (currentSpriteNumber <from or currentSpriteNumber>=to)
		currentSpriteNumber = from;

	changeSprite(currentSpriteNumber);
}

void MP::MapAnimation::setScale(float x, float y)
{
	_obj_sprite.setScale(x, y);
}

void MP::MapAnimation::setOrigin(int x, int y)
{
	_obj_sprite.setOrigin(x, y);
}
