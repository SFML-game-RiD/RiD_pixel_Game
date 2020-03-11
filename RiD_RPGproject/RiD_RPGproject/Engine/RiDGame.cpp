#pragma once

#include "RiDGame.h"

namespace RiD
{
	void RiDGame::Exec()
	{
		sf::Event event;
		while (this->_data->window.isOpen()) //program main loop
		{
			while (this->_data->window.pollEvent(event)) //handling events
			{

			}
		}
	}
	RiDGame::RiDGame(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		this->Exec();
	}
}