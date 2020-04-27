#include "GuiPlacesMenu.h"

void MP::GuiPlacesMenu::_create_buttons(sf::Texture* buttonTexture, sf::Font& aFont)
{
	std::shared_ptr<GuiButton> tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 25), sf::Vector2f(-45, 0), aFont, "go to market place");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 175), sf::Vector2f(-32, 0), aFont, "attack the place");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 325), sf::Vector2f(-45, 0), aFont, "check notice board");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 475), sf::Vector2f(40, 0), aFont, "exit");
	_button_array.push_back(tmp);
}

MP::GuiPlacesMenu::GuiPlacesMenu()
{
}

MP::GuiPlacesMenu::GuiPlacesMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture, sf::Font& aFont)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 1920);
	aAnimation.setObiectSpritePosition(0, 0);
	aAnimation.setOrigin(460, 460);

	_create_buttons(buttonTexture, aFont);
}

void MP::GuiPlacesMenu::_select_button(sf::Vector2f mouseCoord)
{
	for (int i = 0; i < _button_array.size(); i++)
	{
		if (mouseCoord.x >= _button_array[i]->getObiectCoord().x and mouseCoord.x <= _button_array[i]->getObiectCoord().x + 275
			and mouseCoord.y >= _button_array[i]->getObiectCoord().y + 112 and mouseCoord.y <= _button_array[i]->getObiectCoord().y + 163)
			_button_array[i]->update(true);
		else
			_button_array[i]->update(false);
	}
}

void MP::GuiPlacesMenu::_press_button(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow)
{
	if (_button_array[0]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::taskClickLeft, true))
	{
		aMainTaskManager.setState(TaskManager::stateType::stateMarketPlace);
	}
	if (_button_array[1]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::taskClickLeft, true))
	{
	}
	if (_button_array[2]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::taskClickLeft, true))
	{
	}
	if (_button_array[3]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::taskClickLeft, true))
	{
		aMainTaskManager.setState(TaskManager::stateType::stateGame);
	}
}

void MP::GuiPlacesMenu::update(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f GuiMouseCoord)
{
	if (aMainTaskManager.getCurrentState() == TaskManager::stateType::statePlacesMenu)
	{
		_select_button(GuiMouseCoord);
		_press_button(aMainTaskManager,aMainWindow);
	}
}

void MP::GuiPlacesMenu::render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow)
{
	if (aMainTaskManager.getCurrentState() == TaskManager::stateType::statePlacesMenu)
		_draw_menu(aMainWindow);
}
