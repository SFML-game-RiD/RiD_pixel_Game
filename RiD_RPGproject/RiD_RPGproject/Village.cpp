#include "Village.h"

MP::Village::Village(/*std::pair<int, int> coord*/ sf::Vector2f coord)
{
	animationMaker.loadObiectTextures("img/mpimg/places/mpvillage.png", 1, 1, 64);
	setObiectCoord(coord);
}
