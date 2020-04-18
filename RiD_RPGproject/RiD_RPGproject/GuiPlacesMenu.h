#ifndef GUIPLACESMENU_H
#define  GUIPLACESMENU_H
#include "GuiMenu.h"
#include "GuiMarketPlace.h"

namespace MP
{

	class GuiPlacesMenu:public GuiMenu
	{
	private:

		void _create_buttons(sf::Texture* buttonTexture, sf::Font& aFont);

	public:

		GuiPlacesMenu();

		GuiPlacesMenu(sf::Texture* placesMenuTexture, sf::Texture* buttonTexture, sf::Font& aFont);

		void selectButton(sf::Vector2f mouseCoord);

		void pressButton(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);

	};
}
#endif // !_GUIPLACESMENU_H_
