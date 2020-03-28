#ifndef _TOWN_H_
#define _TOWN_H_
#include "Places.h" 

namespace MP
{
	class Town :public Places
	{
	public:
		Town(std::pair<int, int> coord);
	};
}
#endif