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

	public:

		GuiMenu();

		GuiMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture, sf::Font& aFont);

		void drawMenu(sf::RenderWindow& aMainWindow);

		virtual void selectButton(sf::Vector2f guiMouseCoord);

		virtual void pressButton(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);

		virtual void update(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f guiMouseCoord);
	};
}
#endif // !_GUIMENU_H_