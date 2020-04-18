#ifndef GUIMAINMENU_H
#define GUIMAINMENU_H
#include "GuiMenu.h"



namespace MP
{
	class GuiMainMenu :public GuiMenu
	{
	private:

		void _create_buttons(sf::Texture* buttonTexture, sf::Font& aFont);


	public:

		GuiMainMenu();

		GuiMainMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture,sf::Font &aFont);
	
		void selectButton(sf::Vector2f mouseCoord);

		void pressButton(TaskManager &aMainTaskManager, sf::RenderWindow &aMainWindow);
	};
}
#endif // !_GUIMENU_H_
