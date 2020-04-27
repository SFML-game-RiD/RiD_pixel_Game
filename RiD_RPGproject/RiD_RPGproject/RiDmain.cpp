#include "RiDmain.h"
#include "Engine/ConfigurationLoader.h"
#include <iostream>
#include "TaskManager.h"

void RiD::RiDmain::_create_window()
{	
	
	//generating obiects
	_a_obiect_generator.generateObiects(_a_obiect_manager);
	std::printf("generated successful \n");
	

	while (_a_camera.getWindow().isOpen()) //program main loop
	{
		if (_a_main_task_manager.getCurrentState() == MP::TaskManager::stateType::stateGame) //If is faster than switch 
		{
			_event_function_for_state_game();
			_calculate_for_state_game();
			_draw_for_state_game();
		}
		else if (_a_main_task_manager.getCurrentState() == MP::TaskManager::stateType::stateMainMenu 
			or _a_main_task_manager.getCurrentState() == MP::TaskManager::stateType::statePlacesMenu
			or _a_main_task_manager.getCurrentState() == MP::TaskManager::stateType::stateMarketPlace)
		{
			_event_function_for_menu();
			_calculate_for_state_menu();
			_draw_for_menu();
		}
	}
}

void RiD::RiDmain::_event_function_for_state_game()
{

	while (_a_camera.getWindow().pollEvent(_event)) //handling events
	{
		if (_event.type == sf::Event::EventType::Closed)
			_a_camera.getWindow().close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			if (_a_main_task_manager.isTaskListEmpty())
			{
				_a_main_task_manager.setState(MP::TaskManager::stateType::stateMainMenu);
			}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			_a_obiect_manager.getPlayer()->tryToMoveUp(_a_obiect_manager.getMap(),_a_main_task_manager);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			_a_obiect_manager.getPlayer()->tryToMoveLeft(_a_obiect_manager.getMap(),_a_main_task_manager);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			_a_obiect_manager.getPlayer()->tryToMoveDown(_a_obiect_manager.getMap(), _a_main_task_manager);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			_a_obiect_manager.getPlayer()->tryToMoveRight(_a_obiect_manager.getMap(), _a_main_task_manager);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			if (_a_main_task_manager.isTaskListEmpty())
				_a_obiect_manager.getPlayer()->goToPlace(_a_obiect_manager.getMap(), _a_main_task_manager);


		if (_event.type == sf::Event::MouseWheelScrolled)
		{
				if (_event.mouseWheelScroll.delta > 0)
					_a_main_task_manager.addTask(MP::TaskNode::taskType::taskZoomIn);
				else
					_a_main_task_manager.addTask(MP::TaskNode::taskType::taskZoomOut);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_a_main_task_manager.addTask(MP::TaskNode::taskType::taskClickLeft);
		}
	}
}

void RiD::RiDmain::_event_function_for_menu()
{
	while (_a_camera.getWindow().pollEvent(_event)) //handling events
	{
		if (_event.type == sf::Event::EventType::Closed)
			_a_camera.getWindow().close();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			if (_a_main_task_manager.getCurrentState() == MP::TaskManager::stateType::stateMarketPlace)
				_a_main_task_manager.setState(MP::TaskManager::stateType::statePlacesMenu);

			if(_a_main_task_manager.getCurrentState() == MP::TaskManager::stateType::statePlacesMenu)
				_a_main_task_manager.setState(MP::TaskManager::stateType::stateGame);

		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(_a_main_task_manager.isTaskListEmpty())
			_a_main_task_manager.addTask(MP::TaskNode::taskType::taskClickLeft);
		}
	
	}
}

void RiD::RiDmain::_calculate_for_state_game()
{
	_a_calculator.startMainGameProcedures(_a_main_task_manager, _a_obiect_manager, _clock, _a_camera);
}

void RiD::RiDmain::_calculate_for_state_menu()
{
	_a_calculator.startMenuProcedures(_a_main_task_manager, _a_obiect_manager, _a_camera);
}

void RiD::RiDmain::_draw_for_state_game()
{
	_a_camera.clearCamera();

	_a_obiect_drawer.drawGame(_a_main_task_manager,_a_camera,_a_obiect_manager);

	_a_camera.drawFrame(); 
}

void RiD::RiDmain::_draw_for_menu()
{
	_a_camera.clearCamera();

	_a_obiect_drawer.drawMenu(_a_main_task_manager,_a_obiect_manager,_a_camera);

	_a_camera.drawFrame();
}


RiD::RiDmain::RiDmain(int width, int height, std::string title)
{
	sf::VideoMode mode = sf::VideoMode::getFullscreenModes()[0];
	_a_camera.getWindow().create(mode, title, sf::Style::Close | sf::Style::Fullscreen);
	

	//_a_camera.getWindow().create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	//_a_camera.getWindow().setFramerateLimit(RiD::ConfigurationLoader::getIntData("video settings", "gameFPS"));
	_a_camera.getWindow().setMouseCursorVisible(false);
	this->_create_window();

}
