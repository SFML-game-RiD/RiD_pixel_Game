#pragma once
#include <SFML/Graphics.hpp>
#include "Places.h" 

namespace MP
{
	class Town :public Places
	{
	public:

		//Town's constructor.
		//@param texturePtr object texture.
		//@param coord object coord.
		Town(sf::Texture* texturePtr, sf::Vector2f coord);
	};
}