#include "RiDmain.h"
#include "Engine/ConfigurationLoader.h"


void RiD::RiDmain::createWindow()
{
	sf::Event event;
	sf::Clock clock;

	aObiectManager.generateObiects();


	while (this->window.isOpen()) //program main loop
	{	
		_event(event);

		_calculate();
		
		_draw(this->window);

	}
}
void RiD::RiDmain::_event(sf::Event &event)
{
		while (this->window.pollEvent(event)) //handling events
		{
			if (event.type == sf::Event::EventType::Closed)
				this->window.close();
		}
}
void RiD::RiDmain::_calculate()
{
}
void RiD::RiDmain::_draw(sf::RenderWindow & mainWindow)
{
	window.clear();

	aObiectManager.drawActiveObiects(mainWindow);

	window.display();
}
RiD::RiDmain::RiDmain(int width, int height, std::string title)
{
	window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(RiD::ConfigurationLoader::getIntData("video settings","gameFPS"));
	this->createWindow();
}
