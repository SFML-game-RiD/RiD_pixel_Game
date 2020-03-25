#pragma once

#include "RealTimeBattle.h"
#include <iostream>

namespace RTB
{
	RealTimeBattle::RealTimeBattle()
	{
		_camera.reset(sf::FloatRect(0, 0, 853, 480));
		_asset_manager.setTexture("player", "img/character.png");
		_asset_manager.setTexture("bot", "img/bot.png");
		_asset_manager.setTexture("arrow", "img/arrow.png");
	}

	RealTimeBattle::~RealTimeBattle()
	{
	}

	void RealTimeBattle::mainLoop(sf::RenderWindow& window)
	{

		window.setView(_camera);

		Player player(_asset_manager.getTexture("player"), 100, _asset_manager.getTexture("arrow"));
		Bot *bot = new Bot(_asset_manager.getTexture("bot"), 100);
		bot->setPosition(sf::Vector2f(120, 120));
		_list_of_bots.push_back(bot);
	


		player.setPosition(sf::Vector2f(120, 120));

		while (window.isOpen())
		{
			while (window.pollEvent(_event)) //handling events
			{
				if (_event.type == sf::Event::EventType::Closed)
					window.close();
			}
			
			//Renders
			window.clear();

			//Bots
			for (std::list<Bot*>::iterator iterator = _list_of_bots.begin(); iterator != _list_of_bots.end(); iterator++)
			{
				if ((*iterator)->isAlive())
				{
					(*iterator)->update(_clock.getElapsedTime());
					(*iterator)->render(window);
				}
			}

			//Player
			if (player.isAlive())
			{
				player.update(_clock.getElapsedTime());
				player.dealDamage(_clock.getElapsedTime(), _list_of_bots, window);
				player.render(window);
			}
			else
				return;
			
			
			window.display();
		}
		for (std::list<Bot*>::iterator iterator = _list_of_bots.begin(); iterator != _list_of_bots.end(); iterator++)
		{
			delete (*iterator);
		}
	}
}