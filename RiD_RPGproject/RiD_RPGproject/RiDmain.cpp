#include "RiDmain.h"
#include "Engine/ConfigurationLoader.h"


void RiD::RiDmain::_create_window()
{
	//############ Generating obiects ##############

	_a_obiect_generator.generateObiects(_a_obiect_manager);
	std::printf("generated \n");

	//##############################################

	while (this->_window.isOpen()) //program main loop
	{	
		_event_function(_event);

		_calculate();
		
		_draw(this->_window);
	}
}

void RiD::RiDmain::_event_function(sf::Event &event)
{

		while (this->_window.pollEvent(event)) //handling events
		{
			if (event.type == sf::Event::EventType::Closed)
				this->_window.close();
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				_a_task_manager.startProcedureGoUp(*_a_obiect_manager.getPlayer());

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				_a_task_manager.startProcedureGoLeft(*_a_obiect_manager.getPlayer());

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				_a_task_manager.startProcedureGoDown(*_a_obiect_manager.getPlayer());

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				_a_task_manager.startProcedureGoRight(*_a_obiect_manager.getPlayer());
		}
		
}

void RiD::RiDmain::_calculate()
{
	_a_obiect_manager.getPlayer()->playerAnimation(_clock, _a_task_manager);


	_a_calculator.startProcedurePlayerMove(_a_task_manager, *_a_obiect_manager.getPlayer(), _clock);
}

void RiD::RiDmain::_draw(sf::RenderWindow & mainWindow)
{
	_window.clear();

	_a_obiect_drawer.drawAllObiects(mainWindow,_a_obiect_manager);

	_window.display();
}
RiD::RiDmain::RiDmain(int width, int height, std::string title)
{
	_window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	_window.setFramerateLimit(RiD::ConfigurationLoader::getIntData("video settings","gameFPS"));
	this->_create_window();
}
