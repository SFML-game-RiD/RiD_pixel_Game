#include "Player.h"
#include "Engine/ConfigurationLoader.h"

MP::Player::Player()
{
	
	objTexture.loadFromFile("img/mpimg/mpcharacter.png");
	objSprite.setTexture(objTexture);
	
	sf::IntRect tmp(96, 0, 96, 96);
	objRectangle = tmp;

	objSprite.setTextureRect(tmp);
	setObiectCoord(RiD::ConfigurationLoader::getIntData("player", "coordinateX"), RiD::ConfigurationLoader::getIntData("player", "coordinateY"));
	setTravelTime(RiD::ConfigurationLoader::getIntData("player", "secondsPerBlock"));

}
