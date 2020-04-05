#pragma once

#define ZOOM_UP 1.05
#define ZOOM_DOWN 0.95

#include <list>
#include "SFML/Graphics.hpp"
#include "../Engine/AssetManager.h"
#include "../Map/TileMap.h"
#include "Player.h"
#include "Swordsman.h"

namespace RTB
{
	class RealTimeBattle
	{
	private:
		sf::Event _event;
		sf::Clock _clock;
		sf::View _camera;
		RiD::AssetManager _asset_manager;
		std::list<Character*> _list_of_enemies;
		TileMap* _tile_map = nullptr;
		float zoom = 1.f;

		void zoomEvent();
	public:
		RealTimeBattle();
		~RealTimeBattle();

		//Main loop of real time battle
		void mainLoop(sf::RenderWindow& window);
	};
}