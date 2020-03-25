#include "MapAnimation.h"

void  MP::MapAnimation::getRectangleArray(int columns, int rows, int squareLength)
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
	objSprite.setPosition(x, y);
}

void MP::MapAnimation::setObiectSpritePosition(std::pair<int, int> coord)
{
	objSprite.setPosition(coord.first, coord.second);
}

sf::Sprite& MP::MapAnimation::getObiectSprite()
{
	return objSprite;
}

void MP::MapAnimation::loadObiectTextures(std::string texturePath, int columns, int rows, int squareLength)
{
	objTexture.loadFromFile(texturePath);
	setObiectTexture(objTexture);
	getRectangleArray(columns, rows, squareLength);
	changeSprite(0);
}

void MP::MapAnimation::setObiectTexture(sf::Texture &texture)
{
	objSprite.setTexture(texture);
}

void MP::MapAnimation::setObiectTextureRect(sf::IntRect &textureRect)
{
	objSprite.setTextureRect(textureRect);
}

void MP::MapAnimation::changeSprite(int spriteNumber)
{
	setObiectTextureRect(_obiect_rectangle_array[spriteNumber]);
	currentSprite = spriteNumber;
}

const std::vector<sf::IntRect>& MP::MapAnimation::getOryginalArray()
{
	return _obiect_rectangle_array;
}

int MP::MapAnimation::getCurrentSprite()
{
	return currentSprite;
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