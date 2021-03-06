#pragma once

#include "SFML/Graphics.hpp"
#include "../Engine/AssetManager.h"
#include "../Engine/Movement.h"
#include "../Map/TileMap.h"

namespace RTB
{
	class RealTimeBattle
	{
		public:
			RealTimeBattle();
			void mainLoop(sf::RenderWindow &window);
	};
}