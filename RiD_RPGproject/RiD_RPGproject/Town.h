#ifndef TOWN_H
#define TOWN_H
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