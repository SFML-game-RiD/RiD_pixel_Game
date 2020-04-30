#include "GuiMenu.h"

void MP::GuiMenu::_create_buttons(sf::Texture* buttonTexture, sf::Font& aFont)
{

}

MP::GuiMenu::GuiMenu()
{
}

MP::GuiMenu::GuiMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture, sf::Font& aFont)
{
}

void MP::GuiMenu::_draw_menu(sf::RenderWindow& aMainWindow)
{
	aMainWindow.draw(aAnimation.getObiectSprite());

	for (unsigned int i = 0; i < _button_array.size(); i++)
	{
		_button_array[i]->render(aMainWindow);
	}
}

void MP::GuiMenu::_select_button(sf::Vector2f mouseCoord)
{
	for (unsigned int i = 0; i < _button_array.size(); i++)
	{
		if (mouseCoord.x >= _button_array[i]->getObiectCoord().x and mouseCoord.x <= _button_array[i]->getObiectCoord().x + 275
			and mouseCoord.y >= _button_array[i]->getObiectCoord().y + 112 and mouseCoord.y <= _button_array[i]->getObiectCoord().y + 163)
			_button_array[i]->update(true);
		else
			_button_array[i]->update(false);
	}
}

void MP::GuiMenu::_press_button(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow)
{

}

void MP::GuiMenu::update(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f mouseCoord)
{
}

void MP::GuiMenu::render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow)
{
}
