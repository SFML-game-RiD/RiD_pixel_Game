#ifndef _PAWNOBIECT_H_
#define _PAWNOBIECT_H_

#include "ActiveObiect.h"
#include "Map.h"

namespace MP 
{
	class PawnObiect:public ActiveObiect
	{
	private:

	public:


		bool checkGoUp(Map & aMap);

		bool checkGoDown(Map & aMap);

		bool checkGoLeft(Map & aMap);

		bool checkGoRight(Map & aMap);

	};
}
#endif
