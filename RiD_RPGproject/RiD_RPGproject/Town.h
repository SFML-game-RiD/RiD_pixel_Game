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
		Town(RiD::AssetManager& aAssetManager, sf::Vector2f coord);
	};
}