#include "Tree.h"


MP::Tree::Tree(sf::Texture* texturePtr, sf::Vector2f coord, float treeScale)
{
	aAnimation.loadObiectTextures( texturePtr, 2, 2, 64);
	setObiectCoord(coord);
	aAnimation.setOrigin(32, 55);
	aAnimation.setScale(treeScale, treeScale);
	

	_obj_animation_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("game settings", "blockLength"));
	
}
void MP::Tree::treeAnimation(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(0, 3);
		setLastActiveAnimation(globalClock);
	}
}
