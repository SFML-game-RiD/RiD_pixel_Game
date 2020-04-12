#include "GuiMenu.h"




MP::GuiMenu::GuiMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 1920);
	aAnimation.setOrigin(-332, 0);

	_start_button_coord.x = 1150;
	_start_button_coord.y = 475;

	_save_button_coord.x = 1150;
	_save_button_coord.y = 625;

	_load_button_coord.x = 1150;
	_load_button_coord.y = 775;

	_exit_button_coord.x = 1150;
	_exit_button_coord.y = 925;

	_start_button = std::make_unique<GuiButton>(buttonTexture, _start_button_coord);
	_save_button = std::make_unique<GuiButton>(buttonTexture, _save_button_coord);
	_load_button = std::make_unique<GuiButton>(buttonTexture, _load_button_coord);
	_exit_button = std::make_unique<GuiButton>(buttonTexture, _exit_button_coord);
}

void MP::GuiMenu::drawMenu(sf::RenderWindow& aMainWindow)
{
//	aMainWindow.draw()
}

