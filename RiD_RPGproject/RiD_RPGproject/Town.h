#ifndef _TOWN_H_
#define _TOWN_H_
#include "Places.h" 

namespace MP
{
	class Town :public Places
	{
	public:
		Town(sf::Texture* texturePtr, sf::Vector2f coord);
	};
}
#endif