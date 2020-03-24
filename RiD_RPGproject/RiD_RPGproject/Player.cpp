#include "Player.h"
#include "Engine/ConfigurationLoader.h"
#include "MapAnimation.h"

MP::Player::Player()
{
	animationMaker.loadObiectTextures("img/mpimg/mpcharacter.png",3,4,96);
	
	animationMaker.changeSprite(6);

	objSleepTime = sf::milliseconds(RiD::ConfigurationLoader::getIntData("player", "coordinateX"));
	
	setObiectCoord(RiD::ConfigurationLoader::getIntData("player", "coordinateX"), RiD::ConfigurationLoader::getIntData("player", "coordinateY"));
	

	

}