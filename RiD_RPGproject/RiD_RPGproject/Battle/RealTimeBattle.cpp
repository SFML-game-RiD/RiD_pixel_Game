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
		sf::View camera;
		camera.reset(sf::FloatRect(0, 0, 853, 480));
		window.setView(camera);
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				character.triggerAttack();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				character.triggerShot();

			if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) &&
				(!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
				(character.isAttackTriggered() == false) && character.isShotTriggered() == false)
				character.idle(clock.getElapsedTime());

			character.swordSwing(clock.getElapsedTime());
			character.bowShot(clock.getElapsedTime());


			window.clear();
			window.draw(character.getSprite());
			window.display();
		}
	}
}