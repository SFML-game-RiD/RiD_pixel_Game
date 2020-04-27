#ifndef GUIMENU_H
#define GUIMENU_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Obiect.h"
#include "GuiButton.h"
#include "TaskManager.h"


namespace MP
{
	class GuiMenu:public Obiect
	{
	protected:

		std::vector< std::shared_ptr<GuiButton>> _button_array;

	 	virtual	void _create_buttons(sf::Texture* buttonTexture, sf::Font& aFont);

		virtual void _select_button(sf::Vector2f guiMouseCoord);

		virtual void _press_button(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);

		void _draw_menu(sf::RenderWindow& aMainWindow);

	public:

		GuiMenu();

		GuiMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture, sf::Font& aFont);

		virtual void update(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f guiMouseCoord);

		virtual void render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);
	};
}
#endif // !_GUIMENU_H_