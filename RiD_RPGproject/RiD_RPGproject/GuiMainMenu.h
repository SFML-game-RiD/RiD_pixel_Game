#ifndef GUIMAINMENU_H
#define GUIMAINMENU_H
#include "GuiMenu.h"



namespace MP
{
	class GuiMainMenu :public GuiMenu
	{
	private:

		void _create_buttons(sf::Texture* buttonTexture, sf::Font& aFont);

		void _select_button(sf::Vector2f mouseCoord);

		void _press_button(TaskManager &aMainTaskManager, sf::RenderWindow &aMainWindow);

	public:

		GuiMainMenu();

		GuiMainMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture,sf::Font &aFont);
	
		void update(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f mouseCoord);

		void render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);
	};
}
#endif // !_GUIMENU_H_
