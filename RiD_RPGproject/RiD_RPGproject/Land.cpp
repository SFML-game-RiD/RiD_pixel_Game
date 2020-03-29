#include "Land.h"

MP::Land::Land(int x, int y)
{
	animationMaker.loadObiectTextures("img/mpimg/mpgrass.png", 1, 1, 64);

	setObiectCoord(x, y);
}
 