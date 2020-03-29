#include "Tree.h"

MP::Tree::Tree(/*std::pair<int, int> coord*/sf::Vector2f coord)
{
	animationMaker.loadObiectTextures("img/mpimg/mptree.png", 2, 2, 64);
	setObiectCoord(coord);
	animationMaker.setOrigin(32, 55);
	obj_animation_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("game settings", "blockLength"));
	
}
void MP::Tree::treeAnimation(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		animationMaker.setNextSprite(0, 3);
		setLastActiveAnimation(globalClock);
	}
}
