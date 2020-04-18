#pragma once

#include "RealTimeBattle.h"

namespace RTB
{
	void RealTimeBattle::_zoomEvent()
	{
		if (_event.mouseWheel.delta == -1)
		{
			if (zoom * ZOOM_UP >= 1.2)
				return;
			else
			{
				zoom *= ZOOM_UP;
				_camera.zoom(ZOOM_UP);
			}
		}
		else if (_event.mouseWheel.delta == 1)
		{
			if (zoom * ZOOM_DOWN <= 0.8)
				return;
			else
			{
				zoom *= ZOOM_DOWN;
				_camera.zoom(ZOOM_DOWN);
			}
		}
	}

	void RealTimeBattle::_armyCreation()
	{
		unsigned seed = static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		std::mt19937 RNG(seed);
		std::uniform_real_distribution<float> enemy_position_height(12, 36);
		std::uniform_real_distribution<float> enemy_position_width(1, 5);
		sf::Vector2f position;

		for (unsigned short i = 0; i < 8; ++i)
			_list_of_enemies.emplace_back(new Swordsman(_asset_manager.getTexture("enemy_swordsman"), 100, _tile_map->getWalkableArea()));
		for (unsigned short i = 0; i < 4; ++i)
			_list_of_enemies.emplace_back(new Archer(_asset_manager.getTexture("enemy_archer"), 100, _asset_manager.getTexture("arrow"), _tile_map->getWalkableArea()));
		for (unsigned short i = 0; i < 4; ++i)
			_list_of_enemies.emplace_back(new Spearman(_asset_manager.getTexture("enemy_spearman"), 100, _tile_map->getWalkableArea()));
		for (std::list<std::shared_ptr<Character>>::iterator iterator = _list_of_enemies.begin(); iterator != _list_of_enemies.end(); iterator++)
		{
			position.x = enemy_position_height(RNG) * 25;
			position.y = enemy_position_width(RNG) * 25;
			position = _tile_map->_twoDToIso(position);
			(*iterator)->setPosition({ position.x,position.y });
			while (_checkPlacementCollisions(iterator))
			{
				position.x = enemy_position_height(RNG) * 25;
				position.y = enemy_position_width(RNG) * 25;
				position = _tile_map->_twoDToIso(position);
				(*iterator)->setPosition({ position.x,position.y });
			}
		}

		for (unsigned short i = 0; i < 8; ++i)
			_list_of_allies.emplace_back(new Swordsman(_asset_manager.getTexture("ally_swordsman"), 100, _tile_map->getWalkableArea()));
		for (unsigned short i = 0; i < 4; ++i)
			_list_of_allies.emplace_back(new Archer(_asset_manager.getTexture("ally_archer"), 100, _asset_manager.getTexture("arrow"), _tile_map->getWalkableArea()));
		for (unsigned short i = 0; i < 3; ++i)
			_list_of_allies.emplace_back(new Spearman(_asset_manager.getTexture("ally_spearman"), 100, _tile_map->getWalkableArea()));

		_list_of_allies.emplace_back(new Player(_asset_manager.getTexture("player"), 100, _asset_manager.getTexture("arrow")));
		_player = _list_of_allies.back();

		std::uniform_real_distribution<float> ally_position_height(12, 36);
		std::uniform_real_distribution<float> ally_position_width(59, 63);

		for (std::list<std::shared_ptr<Character>>::iterator iterator = _list_of_allies.begin(); iterator != _list_of_allies.end(); iterator++)
		{
			position.x = ally_position_height(RNG) * 25;
			position.y = ally_position_width(RNG) * 25;
			position = _tile_map->_twoDToIso(position);
			(*iterator)->setPosition({ position.x,position.y });
			while (_checkPlacementCollisions(iterator))
			{
				position.x = ally_position_height(RNG) * 25;
				position.y = ally_position_width(RNG) * 25;
				position = _tile_map->_twoDToIso(position);
				(*iterator)->setPosition({ position.x,position.y });
			}
		}
	}

	bool RealTimeBattle::_checkPlacementCollisions(std::list<std::shared_ptr<Character>>::iterator character)
	{
		sf::Vector2f position;
		position.x = ((2 * (*character)->getPosition().y + (*character)->getPosition().x) / 2) / 25;
		position.y = ((2 * (*character)->getPosition().y - (*character)->getPosition().x) / 2) / 25;
		if (position.x > _tile_map->getHeight() || position.x < 0 ||
			position.y > _tile_map->getWidth() || position.y < 0)//checks if character is not situated "inside" the map
			return true;//collides
		else ///////////to do
		{
			return false;// do not collides
		}
	}

	RealTimeBattle::RealTimeBattle()
	{
		_camera.reset(sf::FloatRect(0, 0, 853, 480));
		_asset_manager.setTexture("player", "img/character.png");
		_asset_manager.setTexture("enemy_swordsman", "img/enemy_swordsman.png");
		_asset_manager.setTexture("ally_swordsman", "img/ally_swordsman.png");
		_asset_manager.setTexture("enemy_archer", "img/enemy_archer.png");
		_asset_manager.setTexture("ally_archer", "img/ally_archer.png");
		_asset_manager.setTexture("ally_spearman", "img/ally_spearman.png");
		_asset_manager.setTexture("enemy_spearman", "img/enemy_spearman.png");
		_asset_manager.setTexture("arrow", "img/arrow.png");
		_asset_manager.setTexture("window_border", "img/WindowBorder.png");

		_window_border.setTexture(_asset_manager.getTexture("window_border"));
	}

	RealTimeBattle::~RealTimeBattle()
	{
	}

	void RealTimeBattle::mainLoop(sf::RenderWindow& window)
	{
		_tile_map = std::unique_ptr<TileMap>(new TileMap({ 50,50 }));

		this->_armyCreation();
		while (window.isOpen())
		{
			while (window.pollEvent(_event)) //handling events
			{
				if (_event.type == sf::Event::EventType::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				if (_event.type == sf::Event::MouseWheelMoved)
					this->_zoomEvent();
			}

			//Renders
			window.clear();
			window.draw(_window_border);
			_tile_map->drawTiles(window);

			//Bots
			if (_player->isAlive())
				_camera.setCenter(_player->getPosition()); //camera is centered on the player

			for (std::list<std::shared_ptr<Character>>::iterator iterator = _list_of_enemies.begin(); iterator != _list_of_enemies.end(); iterator++)
			{
				if (!(*iterator)->isAlive())
					(*iterator)->deadBody(window);
				else continue;
			}
			for (std::list<std::shared_ptr<Character>>::iterator iterator = _list_of_allies.begin(); iterator != _list_of_allies.end(); iterator++)
			{
				if (!(*iterator)->isAlive())
					(*iterator)->deadBody(window);
				else continue;
			}

			for (std::list<std::shared_ptr<Character>>::iterator iterator = _list_of_enemies.begin(); iterator != _list_of_enemies.end(); iterator++)
			{
				if ((*iterator)->isAlive())
				{
					(*iterator)->update(_clock.getElapsedTime(), _tile_map->getCollidableObjects(), _list_of_allies, window);
					(*iterator)->dealDamage(_clock.getElapsedTime(), _list_of_allies, window);
					(*iterator)->render(window);
				}
			}

			for (std::list<std::shared_ptr<Character>>::iterator iterator = _list_of_allies.begin(); iterator != _list_of_allies.end(); iterator++)
			{
				if ((*iterator)->isAlive())
				{
					(*iterator)->update(_clock.getElapsedTime(), _tile_map->getCollidableObjects(), _list_of_enemies, window);
					(*iterator)->dealDamage(_clock.getElapsedTime(), _list_of_enemies, window);
					(*iterator)->render(window);
				}
			}
			_tile_map->drawObjects(window);
			window.setView(_camera);
			window.display();
		}
	}
}