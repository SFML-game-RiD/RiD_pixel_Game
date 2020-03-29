#include "Castle.h"

MP::Castle::Castle(/*std::pair<int, int> coord*/ sf::Vector2f coord)
{
	animationMaker.loadObiectTextures("img/mpimg/places/mpcastle.png", 1, 1, 64);
	setObiectCoord(coord);
}
