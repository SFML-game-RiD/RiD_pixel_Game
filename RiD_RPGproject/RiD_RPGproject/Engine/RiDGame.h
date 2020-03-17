#pragma once

#include <memory>

#include "Animation.h"
#include "Movement.h"
#include "StateMachine.h"
#include "InputManager.h"
#include "../Battle/RealTimeBattle.h"

namespace RiD
{
	struct gameDat // **********************config loader needed here***************************
	{
		sf::RenderWindow window;
		StateMachine state_machine;
		AssetManager asset_manager;
		InputManager input_manager;
	};

	typedef std::shared_ptr<gameDat> gameDatReference;

	class RiDGame
	{
	private:
		//const double _fps = 1.0f / 60.0f; //60 fps
		sf::Clock _clock;
		gameDatReference _data = std::make_shared<gameDat>();

		//Executes creation of window
		void Exec();
	public:
		/*
		Constructor that creates main window
		@param width width of the window
		@param height height of the window
		@param title title on the top bar
		*/
		RiDGame(int width, int height, std::string title);
		~RiDGame();
	};
}