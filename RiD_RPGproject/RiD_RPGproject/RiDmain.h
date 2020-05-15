#pragma once

#include "SFML/Graphics.hpp"
#include "ObjectDrawer.h"
#include "Move.h"
#include "ObjectManager.h"
#include "ObjectGenerator.h"
#include "TaskManager.h"
#include "Calculator.h"
#include "Camera.h"
#include "Music.h"

namespace RiD
{
	class RiDmain
	{
	private:


		//############# OBIECT MANAGING ##############

		MP::ObjectDrawer _a_obiect_drawer;

		MP::ObjectManager _a_obiect_manager;

		MP::ObjectGenerator _a_obiect_generator;

		//############################################

		//############# OBIECT MODIFYING #############

		MP::Calculator _a_calculator;

		MP::TaskManager _a_main_task_manager;

		//############################################

		MP::Camera _a_camera;

		sf::Event _event;

		sf::Clock _clock;

		MP::Music _music;

		MP::SoundManager _a_sound_manager;

     	//Executes creation of window
		void _create_window();

		void _event_function_for_state_game();

		void _calculate_for_state_game();

		void _draw_for_state_game();


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