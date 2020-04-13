#ifndef _GUIMENU_H_
#define _GUIMENU_H_
#include <SFML/Graphics.hpp>
#include "Obiect.h"
#include "GuiButton.h"
#include "TaskManager.h"

namespace MP
{
	class GuiMenu :public Obiect
	{
		sf::Vector2f _start_button_coord;
		sf::Vector2f _save_button_coord;
		sf::Vector2f _load_button_coord;
		sf::Vector2f _exit_button_coord;

		std::unique_ptr<GuiButton> _start_button;
		std::unique_ptr<GuiButton> _save_button;
		std::unique_ptr<GuiButton> _load_button;
		std::unique_ptr<GuiButton> _exit_button;


	public:

		GuiMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture,sf::Font &aFont);

		void drawMenu(sf::RenderWindow& aMainWindow);
	
		void selectButton(sf::Vector2f mouseCoord);

		void pressButton(TaskManager &aMainTaskManager, sf::RenderWindow &aMainWindow);
	};
}
#endif // !_GUIMENU_H_
