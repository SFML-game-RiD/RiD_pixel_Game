#ifndef _VILLAGE_H_
#define _VILLAGE_H_
#include "Places.h" 

namespace MP
{
	class Village :public Places
	{
	public:

		Village(/*std::pair<int, int> coord*/ sf::Vector2f coord);
	};
}
#endif