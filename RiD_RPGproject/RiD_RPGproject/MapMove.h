#pragma once
#include "ActiveObiect.h"


namespace MP
{
	class MapMove
	{
	public:

		void moveBlockDown(ActiveObiect& obiect,int blockLength);

		void moveBlockUp(ActiveObiect& obiect, int blockLength);

		void moveBlockRight(ActiveObiect& obiect, int blockLength);

		void moveBlockLeft(ActiveObiect& obiect, int blockLength);

		void movePixelDown(ActiveObiect & obiect);

		void movePixelUp(ActiveObiect & obiect);

		void movePixelRight(ActiveObiect & obiect);

		void movePixelLeft(ActiveObiect & obiect);
	};
}
