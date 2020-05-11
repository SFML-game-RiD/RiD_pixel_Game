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
		Castle(RiD::AssetManager &aAssetManager, sf::Vector2f coord);
	};
}