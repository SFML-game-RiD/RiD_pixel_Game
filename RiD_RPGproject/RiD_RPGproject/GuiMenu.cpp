#include "GuiMenu.h"

void MP::GuiMenu::_create_buttons(sf::Texture* buttonTexture, sf::Font& aFont)
{
	//std::shared_ptr<GuiButton> tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 25), sf::Vector2f(38, 0), aFont, "start");
	//_button_array.push_back(tmp);

	//tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 175), sf::Vector2f(10, 0), aFont, "save game");
	//_button_array.push_back(tmp);

	//tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 325), sf::Vector2f(10, 0), aFont, "load game");
	//_button_array.push_back(tmp);

	//tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 475), sf::Vector2f(40, 0), aFont, "exit");
	//_button_array.push_back(tmp);
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
}

void MP::GuiMenu::pressButton(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow)
{
}
