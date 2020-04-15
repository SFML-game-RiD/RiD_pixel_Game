#ifndef VILLAGE_H
#define VILLAGE_H
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