#include "Player.h"
#include "Engine/ConfigurationLoader.h"

MP::Player::Player()
{
	objCoord.first = RiD::ConfigurationLoader::getIntData("player", "coordinateX");
	objCoord.second = RiD::ConfigurationLoader::getIntData("player", "coordinateY");
	objTexture.loadFromFile("img/mpimg/mpcharacter.png");
	objSprite.setTexture(objTexture);
	objSprite.setPosition(objCoord.first, objCoord.second);

	sf::IntRect tmp(96, 0, 96, 96);
	objRectangle = tmp;

	objSprite.setTextureRect(tmp);
}
