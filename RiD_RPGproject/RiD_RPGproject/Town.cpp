#include "Town.h"

MP::Town::Town(std::pair<int, int> coord)
{
	animationMaker.loadObiectTextures("img/mpimg/places/mptown.png", 1, 1, 64);
	setObiectCoord(coord);
}
