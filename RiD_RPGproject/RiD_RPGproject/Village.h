#ifndef _VILLAGE_H_
#define _VILLAGE_H_
#include "Places.h" 

namespace MP
{
	class Village :public Places
	{
	public:

		Village(sf::Texture* texturePtr, sf::Vector2f coord);
	};
}
#endif