#pragma once

#include <list>
#include "SFML/Graphics.hpp"
#include "../Engine/AssetManager.h"
#include "../Map/TileMap.h"
#include "Player.h"
#include "Bot.h"

namespace RTB
{
	class RealTimeBattle
	{
	private:
		sf::Event _event;
		sf::Clock _clock;
		sf::View _camera;
		RiD::AssetManager _asset_manager;
		std::list<Bot*> _list_of_bots;
	public:
		RealTimeBattle();
		~RealTimeBattle();

		//Main loop of real time battle
		void mainLoop(sf::RenderWindow& window);
	};
}