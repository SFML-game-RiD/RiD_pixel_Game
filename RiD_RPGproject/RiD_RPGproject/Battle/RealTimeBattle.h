#pragma once

#define ZOOM_UP 1.05
#define ZOOM_DOWN 0.95

#include <list>
#include <memory>
#include <chrono>
#include <random>
#include "../vld.h"
#include "SFML/Graphics.hpp"
#include "../Engine/AssetManager.h"
#include "../Map/TileMap.h"
#include "Player.h"
#include "Swordsman.h"
#include "Archer.h"
#include "Spearman.h"
#include "GUI.h"

namespace RTB
{
	class RealTimeBattle
	{
	private:
		std::shared_ptr<Character> _player;
		sf::RenderWindow* _window;
		sf::Event _event;
		sf::View _camera;
		sf::Clock _clock;
		RiD::AssetManager _asset_manager;
		std::list<std::shared_ptr<Character>> _list_of_enemies;
		std::list<std::shared_ptr<Character>> _list_of_allies;
		std::unique_ptr<TileMap> _tile_map;
		std::unique_ptr<RTBGUI::GUI> _user_interface;
		double _zoom = 1.f;
		bool _is_paused;

		void _zoomEvent();
		void _armyCreation();
		bool _checkPlacementCollisions(std::list<std::shared_ptr<Character>>::iterator character);
		bool _isEnemyTeamDead();
		bool _isAllyTeamDead();
	public:
		RealTimeBattle(sf::RenderWindow& window);
		~RealTimeBattle();

		//Main loop of real time battle
		void mainLoop();
	};
}