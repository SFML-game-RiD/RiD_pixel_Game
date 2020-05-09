#pragma once
#include "GuiMenu.h"



namespace MP
{
	class GuiMainMenu :public GuiMenu
	{
	private:

		//Creates buttons.
		//@param buttonTexture button's texture.
		//@param aFont game's font.
		void _create_buttons(sf::Texture* buttonTexture, sf::Font& aFont);

		//Checks mouse coordinates and makes button active.
		//mouseCoord mouse's coordinates.
		void _select_button(SoundManager& aSoundManager, TaskManager& aTaskManager, sf::Vector2f mouseCoord);

		//Starts procedures relative to pressed button.
		//@param aMainTaskManager main task manager.
		//@param aMainWindow game's main window.
		void _press_button(TaskManager &aMainTaskManager, sf::RenderWindow &aMainWindow);

	public:

		//GUI's constructor.
		GuiMainMenu();

		//GUI's constructor.
		//@param texturePtr place's texture.
		//@param buttonTexture button's texture.
		//@aFont game's font.
		GuiMainMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture,sf::Font &aFont);
	
		//Updates GUI.
		//@param aMainTaskManager main task manager.
		//@param aMainWindow game's main window.
		//@param guiMouseCoord mouse's coord from gui view.
		void update(SoundManager& aSoundManager, TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f guiMouseCoord);

		//Draws GUI.
		//@param aMainTaskManager main task manager.
		//@param aMainWindow game's main window.
		void render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);
	};
}