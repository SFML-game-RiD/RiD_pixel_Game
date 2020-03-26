#include "Land.h"

MP::Land::Land(int x, int y, char mark)
{
	animationMaker.loadObiectTextures("img/mpimg/mpgrass.png", 1, 1, 64);

	animationMaker.setObiectSpritePosition(x, y);
}
