#pragma once

#include "RealTimeBattle.h"
#include <iostream>

namespace RTB
{
	RealTimeBattle::RealTimeBattle()
	{
		_camera.reset(sf::FloatRect(0, 0, 853, 480));
		_asset_manager.setTexture("player", "img/character.png");
	}
	void RealTimeBattle::mainLoop(sf::RenderWindow& window)
	{
		window.setView(_camera);

		Player player(_asset_manager.getTexture("player"));
		player.setPosition({ 120.0, 120.0 });

		while (window.isOpen())
		{
			while (window.pollEvent(_event)) //handling events
			{
				if (_event.type == sf::Event::EventType::Closed)
					window.close();
			}
			
			//Renders
			window.clear();
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