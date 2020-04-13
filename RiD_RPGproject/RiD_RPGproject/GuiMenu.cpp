#include "GuiMenu.h"

#include <iostream>


MP::GuiMenu::GuiMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture, sf::Font &aFont)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 1920);
	aAnimation.setObiectSpritePosition(0, 0);
	aAnimation.setOrigin(460,460);

	_start_button_coord.x = 365;
	_start_button_coord.y =	25;

	_save_button_coord.x = 365;
	_save_button_coord.y = 175;

	_load_button_coord.x = 365;
	_load_button_coord.y = 325;

	_exit_button_coord.x = 365;
	_exit_button_coord.y = 475;

	_start_button = std::make_unique<GuiButton>(buttonTexture, _start_button_coord,aFont,"start");
	_save_button = std::make_unique<GuiButton>(buttonTexture, _save_button_coord, aFont,"save game");
	_load_button = std::make_unique<GuiButton>(buttonTexture, _load_button_coord, aFont,"load game");
	_exit_button = std::make_unique<GuiButton>(buttonTexture, _exit_button_coord, aFont,"exit");
}

void MP::GuiMenu::drawMenu(sf::RenderWindow& aMainWindow)
{
	aMainWindow.draw(aAnimation.getObiectSprite());
	aMainWindow.draw(_start_button->aAnimation.getObiectSprite());
	aMainWindow.draw(_save_button->aAnimation.getObiectSprite());
	aMainWindow.draw(_load_button->aAnimation.getObiectSprite());
	aMainWindow.draw(_exit_button->aAnimation.getObiectSprite());
	aMainWindow.draw(_start_button->getText());
	aMainWindow.draw(_save_button->getText());
	aMainWindow.draw(_load_button->getText());
	aMainWindow.draw(_exit_button->getText());

}

void MP::GuiMenu::selectButton(sf::Vector2f mouseCoord)
{

	if (mouseCoord.x >= _start_button_coord.x and mouseCoord.x <= _start_button_coord.x + 275
		and mouseCoord.y >= _start_button_coord.y + 112 and mouseCoord.y <= _start_button_coord.y + 163)
		_start_button->setButtonActive(true);
	else
		_start_button->setButtonActive(false);

	if (mouseCoord.x >= _exit_button_coord.x and mouseCoord.x <= _exit_button_coord.x + 275
		and mouseCoord.y >= _exit_button_coord.y + 112 and mouseCoord.y <= _exit_button_coord.y + 163)
		_exit_button->setButtonActive(true);
	else
		_exit_button->setButtonActive(false);

	if (mouseCoord.x >= _save_button_coord.x and mouseCoord.x <= _save_button_coord.x + 275
		and mouseCoord.y >= _save_button_coord.y + 112 and mouseCoord.y <= _save_button_coord.y + 163)
		_save_button->setButtonActive(true);
	else
		_save_button->setButtonActive(false);

	if (mouseCoord.x >= _load_button_coord.x and mouseCoord.x <= _load_button_coord.x + 275
		and mouseCoord.y >= _load_button_coord.y + 112 and mouseCoord.y <= _load_button_coord.y + 163)
		_load_button->setButtonActive(true);
	else
		_load_button->setButtonActive(false);

}

void MP::GuiMenu::pressButton(TaskManager& aTaskManager,  sf::RenderWindow& aMainWindow)
{
	if (_start_button->getButtonActive() == true and aTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft)
	{
		aTaskManager.resetOrdersAndReply();
		aTaskManager.setState(TaskManager::stateType::stateGame);
	}
	if (_save_button->getButtonActive() == true and aTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft)
	{
		aTaskManager.resetOrdersAndReply();
	}
	if (_load_button->getButtonActive() == true and aTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft)
	{
		aTaskManager.resetOrdersAndReply();
	}
	if (_exit_button->getButtonActive() == true and aTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft)
	{
		aTaskManager.resetOrdersAndReply();
		aMainWindow.close();
	}
}

