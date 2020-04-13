#ifndef _GUIMENU_H_
#define _GUIMENU_H_
#include <SFML/Graphics.hpp>
#include "Obiect.h"
#include "GuiButton.h"
#include "TaskManager.h"
#include <vector>

namespace MP
{
	class GuiMenu :public Obiect
	{
		std::vector< std::shared_ptr<GuiButton>> _button_array;

		void _create_buttons(sf::Texture* buttonTexture, sf::Font& aFont);

	public:

		GuiMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture,sf::Font &aFont);

		void drawMenu(sf::RenderWindow& aMainWindow);
	
		void selectButton(sf::Vector2f mouseCoord);

		void pressButton(TaskManager &aMainTaskManager, sf::RenderWindow &aMainWindow);
	};
}
#endif // !_GUIMENU_H_
