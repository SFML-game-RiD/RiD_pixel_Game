#pragma once

#include "RealTimeBattle.h"

namespace RTB
{
	void RealTimeBattle::zoomEvent()
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
	RealTimeBattle::RealTimeBattle()
	{
		_camera.reset(sf::FloatRect(0, 0, 853, 480));
		_asset_manager.setTexture("player", "img/character.png");
		_asset_manager.setTexture("enemy_swordsman", "img/enemy_swordsman.png");
		_asset_manager.setTexture("enemy_archer", "img/enemy_archer.png");
		_asset_manager.setTexture("arrow", "img/arrow.png");
	}

	RealTimeBattle::~RealTimeBattle()
	{
	}

	void RealTimeBattle::mainLoop(sf::RenderWindow& window)
	{
		_tile_map = new TileMap({ 50,50 });
		window.setView(_camera);

		Player player(_asset_manager.getTexture("player"), 100, _asset_manager.getTexture("arrow"));
		Swordsman* bot = new Swordsman(_asset_manager.getTexture("enemy_swordsman"), 100);
		bot->setPosition(sf::Vector2f(145, 230));
		_list_of_enemies.push_back(bot);

		player.setPosition(sf::Vector2f(200, 200));
		while (window.isOpen())
		{
			while (window.pollEvent(_event)) //handling events
			{
				if (_event.type == sf::Event::EventType::Closed)
					window.close();
				if (_event.type == sf::Event::MouseWheelMoved)
					this->zoomEvent();
			}

			//Renders
			window.clear();
			_tile_map->drawTiles(window);
			//Bots
			for (std::list<Character*>::iterator iterator = _list_of_enemies.begin(); iterator != _list_of_enemies.end(); iterator++)
			{
				if ((*iterator)->isAlive())
				{
					(*iterator)->update(_clock.getElapsedTime(), _tile_map->getCollidableObjects());
					(*iterator)->render(window);
				}
			}

			//Player
			if (player.isAlive())
			{
				player.update(_clock.getElapsedTime(), _tile_map->getCollidableObjects());
				_camera.setCenter(player.getPosition()); //camera is centered on the player
				player.dealDamage(_clock.getElapsedTime(), _list_of_enemies, window);
				std::cout << "iso: "<< (int)(player.getPosition().x-player.getPosition().y)/25 << " " << (int)((player.getPosition().x + player.getPosition().y) / 2)/25 << std::endl;
				std::cout << "isoto2d: " << (int)(((2*player.getPosition().y+ player.getPosition().x)/2)/25) << " " << (int)(((2 * player.getPosition().y - player.getPosition().x) / 2) / 25) << std::endl;
				std::cout << "carthesian: " << (int)(player.getPosition().x / 25) << " " << (int)(player.getPosition().y / 25) << std::endl;
				player.render(window);
			}
			else
				return;
			_tile_map->drawObjects(window);
			window.setView(_camera);
			window.display();
		}
		for (std::list<Character*>::iterator iterator = _list_of_enemies.begin(); iterator != _list_of_enemies.end(); iterator++)
		{
			delete (*iterator);
		}
		delete _tile_map;
	}
}