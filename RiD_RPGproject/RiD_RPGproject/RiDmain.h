#pragma once
#include "SFML/Graphics.hpp"
#include "ObiectManager.h"
#include "MapMove.h"

namespace RiD
{
	class RiDmain
	{
	private:

		//Put this variables somewhere!!!

		sf::RenderWindow window;

		MP::ObiectManager aObiectManager;

		MP::MapMove aMapMove;

		int _block_length;

     	//Executes creation of window
		void createWindow();

		void _event(sf::Event& event);

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