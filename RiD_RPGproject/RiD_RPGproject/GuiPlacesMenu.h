#ifndef GUIPLACESMENU_H
#define  GUIPLACESMENU_H
#include "GuiMenu.h"

namespace MP
{

	class GuiPlacesMenu:public GuiMenu
	{
	private:

		void _create_buttons(sf::Texture* buttonTexture, sf::Font& aFont);
	
		void _select_button(sf::Vector2f mouseCoord);

		void _press_button(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);

	public:

		GuiPlacesMenu();

		GuiPlacesMenu(sf::Texture* placesMenuTexture, sf::Texture* buttonTexture, sf::Font& aFont);

		void update(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f guiMouseCoord);
		
		void render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);

	};
}
#endif // !_GUIPLACESMENU_H_
