#include "Castle.h"

MP::Castle::Castle(std::pair<int,int> coord)
{
	animationMaker.loadObiectTextures("img/mpimg/places/mpcastle.png", 1, 1, 64);
	setObiectCoord(coord);
}
