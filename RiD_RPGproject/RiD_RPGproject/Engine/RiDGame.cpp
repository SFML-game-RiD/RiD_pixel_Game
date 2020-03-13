#pragma once

#include "RiDGame.h"

namespace RiD
{
	void RiDGame::Exec()
	{
		sf::Event event;
		sf::Clock clock;

		//Test
		/*sf::Sprite character;
		_data->asset_manager.setTexture("player", "img/character.png");
		character.setTexture(_data->asset_manager.getTexture("player"));
		Animation animation(character);
		animation.addFrame({ sf::IntRect(19,718,27,48),0.01f });
		animation.addFrame({ sf::IntRect(82,718,27,48),0.01f });
		animation.addFrame({ sf::IntRect(147,718,27,48),0.01f });
		animation.addFrame({ sf::IntRect(209,718,27,48),0.01f });
		animation.addFrame({ sf::IntRect(271,718,27,48),0.01f });
		animation.addFrame({ sf::IntRect(334,718,27,48),0.01f });
		animation.addFrame({ sf::IntRect(400,718,27,48),0.01f });
		animation.addFrame({ sf::IntRect(465,718,27,48),0.01f });*/
		//

		while (this->_data->window.isOpen()) //program main loop
		{
			while (this->_data->window.pollEvent(event)) //handling events
			{
				if (event.type == sf::Event::EventType::Closed)
					this->_data->window.close();
			}

			/*animation.update(clock.getElapsedTime().asSeconds());//test
			_data->window.clear();
			_data->window.draw(character);*/
			_data->window.display();

			clock.restart();
		}
	}
	RiDGame::RiDGame(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		this->Exec();
	}
	RiDGame::~RiDGame() {}
}