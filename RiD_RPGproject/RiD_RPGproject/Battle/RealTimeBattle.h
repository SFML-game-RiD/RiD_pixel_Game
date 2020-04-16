#pragma once

#define ZOOM_UP 1.05
#define ZOOM_DOWN 0.95

#include <list>
#include <memory>
#include <chrono>
#include <random>
//#include "../vld.h"
#include "SFML/Graphics.hpp"
#include "../Engine/AssetManager.h"
#include "../Map/TileMap.h"
#include "Player.h"
#include "Swordsman.h"
#include "Archer.h"
#include "Spearman.h"

namespace RTB
{
	class RealTimeBattle
	{
	private:
		std::shared_ptr<Character> _player = nullptr;
		sf::Event _event;
		sf::Clock _clock;
		sf::View _camera;
		RiD::AssetManager _asset_manager;
		std::list<std::shared_ptr<Character>> _list_of_enemies;
		std::list<std::shared_ptr<Character>> _list_of_allies;
		std::unique_ptr<TileMap> _tile_map = nullptr;
		sf::Sprite _window_border;
		float zoom = 1.f;

		void _zoomEvent();
		void _armyCreation();
		bool _checkPlacementCollisions(std::list<std::shared_ptr<Character>>::iterator character);
	public:
		RealTimeBattle();
		~RealTimeBattle();

		//Main loop of real time battle
		void mainLoop(sf::RenderWindow& window);
	};
}