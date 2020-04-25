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

void MP::GuiMenu::drawMenu(sf::RenderWindow& aMainWindow)
{
	aMainWindow.draw(aAnimation.getObiectSprite());

	for (int i = 0; i < _button_array.size(); i++)
	{
		_button_array[i]->drawButton(aMainWindow);
	}
}

void MP::GuiMenu::selectButton(sf::Vector2f mouseCoord)
{
	for (int i = 0; i < _button_array.size(); i++)
	{
		if (mouseCoord.x >= _button_array[i]->getObiectCoord().x and mouseCoord.x <= _button_array[i]->getObiectCoord().x + 275
			and mouseCoord.y >= _button_array[i]->getObiectCoord().y + 112 and mouseCoord.y <= _button_array[i]->getObiectCoord().y + 163)
			_button_array[i]->setButtonActive(true);
		else
			_button_array[i]->setButtonActive(false);
	}
}

void MP::GuiMenu::pressButton(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow)
{

}

void MP::GuiMenu::update(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f mouseCoord)
{
}
