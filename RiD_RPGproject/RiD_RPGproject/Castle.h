#pragma once
#include "Places.h" 

namespace MP
{
	class Castle:public Places
	{
	public:

		//Castle's constructor.
		//@param texturePtr object texture.
		//@param coord object coord.
		Castle(sf::Texture* texturePtr, sf::Vector2f coord);
	};
}