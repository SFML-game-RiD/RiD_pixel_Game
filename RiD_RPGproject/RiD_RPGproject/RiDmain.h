#ifndef _RIDMAIN_H_
#define _RIDMAIN_H_

#include "SFML/Graphics.hpp"
#include "ObiectDrawer.h"
#include "MapMove.h"
#include "ObiectManager.h"
#include "ObiectGenerator.h"
#include "TaskManager.h"
#include "Calculator.h"

namespace RiD
{
	class RiDmain
	{
	private:


		//############# OBIECT MANAGING ##############
		
		MP::ObiectDrawer _a_obiect_drawer;

		MP::ObiectManager _a_obiect_manager;

		MP::ObiectGenerator _a_obiect_generator;

		//############################################

		//Put this variables somewhere!!!
		MP::Calculator _a_calculator;

		MP::TaskManager _a_task_manager;

		sf::RenderWindow _window;

		MP::MapMove _a_map_move;

		sf::Event _event;

		sf::Clock _clock;

     	//Executes creation of window
		void _create_window();

		void _event_function(sf::Event& event);

		void _calculate();

		void _draw(sf::RenderWindow& mainWindow);

	public:
		/*
		Constructor that creates main window
		@param width width of the window
		@param height height of the window
		@param title title on the top bar
		*/
		RiDmain(int width, int height, std::string title);
	};

}
#endif