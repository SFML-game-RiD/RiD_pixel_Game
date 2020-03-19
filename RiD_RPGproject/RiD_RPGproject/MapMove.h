#pragma once
#include "ActiveObiect.h"


namespace MP
{
	class MapMove
	{
	public:

		void moveOnePixelLeft(ActiveObiect obiect);

		void moveOnePixelRight(ActiveObiect obiect);

		void moveOnePixelUp(ActiveObiect obiect);

		void moveOnePixelDown(ActiveObiect obiect);
	};
}
