#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Object.h"
#include "GuiButton.h"
#include "TaskManager.h"


namespace MP
{
	class GuiMenu:public Object
	{
	protected:

		

		std::vector< std::shared_ptr<GuiButton>> _button_array;///Stores buttons.

		//Creates buttons.
		//@param buttonTexture button's texture.
		//@param aFont game's font.
	 	virtual	void _create_buttons(RiD::AssetManager& aAssetManager);

		//Checks mouse coordinates and makes button active.
		//mouseCoord mouse's coordinates.
		virtual void _select_button(SoundManager& aSoundManager, TaskManager& aTaskManager, sf::Vector2f guiMouseCoord);

		//Starts procedures relative to pressed button.
		//@param aMainTaskManager main task manager.
		//@param aMainWindow game's main window.
		virtual void _press_button(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);

		//Draws menu.
		//@param aMainWindow game's window.
		void _draw_menu(sf::RenderWindow& aMainWindow);

	public:

		//GUI's constructor.
		GuiMenu();

		//GUI's constructor.
		//@param placesMenuTexture place's texture.
		//@param buttonTexture button's texture.
		//@aFont game's font.
		GuiMenu(RiD::AssetManager& aAssetManager);

		//Updates GUI.
		//@param aMainTaskManager main task manager.
		//@param aMainWindow game's main window.
		//@param guiMouseCoord mouse's coord from gui view.
		virtual void update(SoundManager& aSoundManager, TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f guiMouseCoord);

		//Draws GUI.
		//@param aMainTaskManager main task manager.
		//@param aMainWindow game's main window.
		virtual void render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);
	};
}
