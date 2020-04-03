#ifndef _CASTLE_H_
#define _CASTLE_H_
#include "Places.h" 

namespace MP
{
	class Castle:public Places
	{
	public:
		Castle(sf::Texture* texturePtr, sf::Vector2f coord);
	};
}
#endif