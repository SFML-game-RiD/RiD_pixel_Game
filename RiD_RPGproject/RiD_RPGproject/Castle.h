#ifndef CASTLE_H
#define CASTLE_H
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