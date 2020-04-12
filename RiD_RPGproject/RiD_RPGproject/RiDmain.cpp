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
		
		_draw();
	}
}

void RiD::RiDmain::_event_function(sf::Event &event)
{

	while (_a_camera.getWindow().pollEvent(event)) //handling events
	{
		if (event.type == sf::Event::EventType::Closed)
			_a_camera.getWindow().close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			_a_camera.getWindow().close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			_a_obiect_manager.getPlayer()->tryToMoveUp(_a_obiect_manager.getMap(),_a_main_task_manager);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			_a_obiect_manager.getPlayer()->tryToMoveLeft(_a_obiect_manager.getMap(),_a_main_task_manager);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			_a_obiect_manager.getPlayer()->tryToMoveDown(_a_obiect_manager.getMap(), _a_main_task_manager);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			_a_obiect_manager.getPlayer()->tryToMoveRight(_a_obiect_manager.getMap(), _a_main_task_manager);

		if (event.type == sf::Event::MouseWheelScrolled)
		{
			if (_a_main_task_manager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskNone)
			{
				if (event.mouseWheelScroll.delta > 0)
					_a_main_task_manager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskZoomIn);
				else
					_a_main_task_manager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskZoomOut);
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (_a_main_task_manager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskNone or
				_a_main_task_manager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskExecuteAutoMove)
			{
				_a_main_task_manager.setTask(MP::TaskManager::taskRange::mainOrder, MP::TaskManager::taskType::taskClickLeft);
			}
		}
	}
}

void RiD::RiDmain::_calculate()
{
	 
		_a_calculator.startProcedurePlayer(_a_main_task_manager, _a_obiect_manager, _clock);

		_a_calculator.startProcedureTrees(_clock, _a_obiect_manager);

		_a_calculator.startProcedureCamera(_a_obiect_manager, _a_main_task_manager, _a_obiect_manager.getPlayer()->getObiectCoord(), _a_camera);

		_a_calculator.startProcedureComputerPlayers(_a_obiect_manager, _clock, _a_obiect_manager.getMap());
	
	    _a_calculator.startProcedureCursor(_a_main_task_manager,_a_obiect_manager, _a_camera);
}

void RiD::RiDmain::_draw()
{
	_a_camera.clearCamera();

	_a_obiect_drawer.drawAllObiects(_a_main_task_manager,_a_camera,_a_obiect_manager);

	_a_camera.drawFrame(); 
}

RiD::RiDmain::RiDmain(int width, int height, std::string title)
{
	//sf::VideoMode mode = sf::VideoMode::getFullscreenModes()[0];
	//_a_camera.getWindow().create(mode, title, sf::Style::Close | sf::Style::Fullscreen);
	
	
	
	_a_camera.getWindow().create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	_a_camera.getWindow().setFramerateLimit(RiD::ConfigurationLoader::getIntData("video settings", "gameFPS"));
	_a_camera.getWindow().setMouseCursorVisible(true);
	this->_create_window();




}
