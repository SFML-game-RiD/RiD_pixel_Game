#include "RiDmain.h"
#include "Engine/ConfigurationLoader.h"
#include <iostream>

void RiD::RiDmain::_create_window()
{	
	
	//############ Generating obiects ##############

	_a_obiect_generator.generateObiects(_a_obiect_manager);
	
	std::printf("generated successful \n");

	//##############################################
	//############ Corecting camera ##############

	_a_camera.changeCamera(_a_obiect_manager.getPlayer()->getObiectCoord());

	//##############################################

	

	while (_a_camera.getWindow().isOpen()) //program main loop
	{
		_event_function(_event);

		_calculate();
		
		_draw(_a_camera.getWindow());
	}
}

void RiD::RiDmain::_event_function(sf::Event &event)
{

	while (_a_camera.getWindow().pollEvent(event)) //handling events
	{
		if (event.type == sf::Event::EventType::Closed)
			_a_camera.getWindow().close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			_a_task_manager.startProcedureGoUp(*_a_obiect_manager.getPlayer(), _a_obiect_manager.getMap());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			_a_task_manager.startProcedureGoLeft(*_a_obiect_manager.getPlayer(),_a_obiect_manager.getMap());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			_a_task_manager.startProcedureGoDown(*_a_obiect_manager.getPlayer(), _a_obiect_manager.getMap());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			_a_task_manager.startProcedureGoRight(*_a_obiect_manager.getPlayer(), _a_obiect_manager.getMap());
		if (event.type == sf::Event::MouseWheelScrolled) 
		{
			if (event.mouseWheelScroll.delta > 0)
				_a_task_manager.startProcedureZoomIn();
			else
				_a_task_manager.startProcedureZoomOut();
		}
	}
		
}

void RiD::RiDmain::_calculate()
{
	_a_calculator.startProcedurePlayerAnimation(_a_task_manager, *_a_obiect_manager.getPlayer(), _clock);

	_a_calculator.startProcedurePlayerMove(_a_task_manager,* _a_obiect_manager.getPlayer(), _clock);

	_a_calculator.startProcedureTreesAnimation(_clock, _a_obiect_manager);

	_a_calculator.startProcedureCameraZoom(_a_task_manager,_a_camera);

	_a_calculator.startProcedureCorrectCamera(_a_task_manager,_a_obiect_manager.getPlayer()->getObiectCoord(), _a_camera);

	_a_calculator.startProcedureComputerPlayer(_a_obiect_manager, _clock, _a_obiect_manager.getMap());
}

void RiD::RiDmain::_draw(sf::RenderWindow & mainWindow)
{
	_a_camera.clearCamera();

	_a_obiect_drawer.drawAllObiects(mainWindow,_a_obiect_manager);

	_a_camera.drawFrame();
}

RiD::RiDmain::RiDmain(int width, int height, std::string title)
{
	sf::VideoMode mode = sf::VideoMode::getFullscreenModes()[0];
	_a_camera.getWindow().create(mode, title, sf::Style::Close | sf::Style::Fullscreen);
	//
	//_a_camera.getWindow().create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	//_a_camera.getWindow().setFramerateLimit(RiD::ConfigurationLoader::getIntData("video settings", "gameFPS"));
	this->_create_window();




}
