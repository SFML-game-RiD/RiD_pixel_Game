#pragma once

#include "RealTimeBattle.h"

namespace RTB
{
	RealTimeBattle::RealTimeBattle()
	{
	}
	void RealTimeBattle::mainLoop(sf::RenderWindow& window)
	{
		sf::Event event;
		sf::Clock clock;
		RiD::AssetManager asset_manager;

		asset_manager.setTexture("player", "img/character.png");
		RiD::Movement character(asset_manager.getTexture("player"));

		while (window.isOpen())
		{
			while (window.pollEvent(event)) //handling events
			{
				if (event.type == sf::Event::EventType::Closed)
					window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				character.walkingUp(clock.getElapsedTime());

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				character.walkingDown(clock.getElapsedTime());

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				character.walkingRight(clock.getElapsedTime());

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				character.walkingLeft(clock.getElapsedTime());
			character.idle(clock.getElapsedTime());

			window.clear();
			window.draw(character.getSprite());
			window.display();
		}
	}
}