#pragma once
#include "ActiveObiect.h"

namespace MP 
{
	class PawnObiect:public ActiveObiect
	{
	public:

		int pastPixel;
		bool isMoving;
	};
}
