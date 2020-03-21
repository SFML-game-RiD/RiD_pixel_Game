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
	}

	RealTimeBattle::~RealTimeBattle()
	{
	}

	void RealTimeBattle::mainLoop(sf::RenderWindow& window)
	{

		window.setView(_camera);

		Player player(_asset_manager.getTexture("player"));
		Bot bot(_asset_manager.getTexture("bot"));
		bot.setPosition(sf::Vector2f(120, 120));
	


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
			bot.update(_clock.getElapsedTime());
			bot.render(window);

			//Player
			if (player.isAlive())
			{
				player.update(_clock.getElapsedTime());
				std::cout << player.getPosition().x << ", " << player.getPosition().y << std::endl;
				player.render(window);
			}
			else
				return;
			
			
			window.display();
		}
	}
}