#include "RiDmain.h"
#include "Engine/ConfigurationLoader.h"


void RiD::RiDmain::createWindow()
{
	aObiectManager.generateObiects();

	sf::Event event;
	sf::Clock clock;

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
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			aMapMove.moveBlockUp(*aObiectManager.getPlayerPtr(),_block_length);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				aMapMove.moveBlockLeft(*aObiectManager.getPlayerPtr(), _block_length);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				aMapMove.moveBlockDown(*aObiectManager.getPlayerPtr(), _block_length);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				aMapMove.moveBlockRight(*aObiectManager.getPlayerPtr(), _block_length);
		}
		
}

void RiD::RiDmain::_calculate()
{
}

void RiD::RiDmain::_draw(sf::RenderWindow & mainWindow)
{
	window.clear();

	aObiectManager.drawAllObiects(mainWindow);

	window.display();
}
RiD::RiDmain::RiDmain(int width, int height, std::string title)
{
	window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(RiD::ConfigurationLoader::getIntData("video settings","gameFPS"));
	_block_length = RiD::ConfigurationLoader::getIntData("video settings", "blockLength");
	this->createWindow();
}
