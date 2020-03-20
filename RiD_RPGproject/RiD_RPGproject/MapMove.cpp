#include "MapMove.h"

void MP::MapMove::moveBlockDown(ActiveObiect& obiect, int blockLength)
{
	while (blockLength != 0)
	{
		movePixelDown(obiect);
		blockLength--;
	}
}

void MP::MapMove::moveBlockUp(ActiveObiect& obiect, int blockLength)
{
	while (blockLength != 0)
	{
		movePixelUp(obiect);
		blockLength--;
	}
}

void MP::MapMove::moveBlockRight(ActiveObiect& obiect, int blockLength)
{
	while (blockLength != 0)
	{
		movePixelRight(obiect);
		blockLength--;
	}
}

void MP::MapMove::moveBlockLeft(ActiveObiect& obiect, int blockLength)
{
	while (blockLength != 0)
	{
		movePixelLeft(obiect);
		blockLength--;
	}
}

void MP::MapMove::movePixelDown(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first, obiect.getObiectCoord().second + 1);
}

void MP::MapMove::movePixelUp(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first, obiect.getObiectCoord().second - 1);
}

void MP::MapMove::movePixelRight(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first+1, obiect.getObiectCoord().second);
}

void MP::MapMove::movePixelLeft(ActiveObiect & obiect)
{
	obiect.setObiectCoord(obiect.getObiectCoord().first-1, obiect.getObiectCoord().second);
}
