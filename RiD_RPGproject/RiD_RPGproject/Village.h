#pragma once
#include <SFML/Graphics.hpp>
#include "Places.h" 

namespace MP
{
	class Village :public Places
	{
	public:

		//Village's constructor.
		//@param texturePtr object texture.
		//@param coord object coord.
		Village(sf::Texture* texturePtr, sf::Vector2f coord);
	};
}