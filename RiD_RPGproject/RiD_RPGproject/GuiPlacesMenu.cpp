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

void MP::GuiPlacesMenu::selectButton(sf::Vector2f mouseCoord)
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

void MP::GuiPlacesMenu::pressButton(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow)
{
	if (_button_array[0]->getButtonActive() == true and aMainTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft)
	{
		aMainTaskManager.resetOrdersAndReply();
		aMainTaskManager.setState(TaskManager::stateType::stateMarketPlace);
	
	}
	if (_button_array[1]->getButtonActive() == true and aMainTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft)
	{
		aMainTaskManager.resetOrdersAndReply();
	}
	if (_button_array[2]->getButtonActive() == true and aMainTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft)
	{
		aMainTaskManager.resetOrdersAndReply();
	}
	if (_button_array[3]->getButtonActive() == true and aMainTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft)
	{
		aMainTaskManager.resetOrdersAndReply();
		aMainTaskManager.setState(TaskManager::stateType::stateGame);
	}
}

void MP::GuiPlacesMenu::update(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f GuiMouseCoord)
{
	if (aMainTaskManager.getCurrentState() == TaskManager::stateType::statePlacesMenu)
	{
		selectButton(GuiMouseCoord);
		pressButton(aMainTaskManager,aMainWindow);
	}
}

void MP::GuiPlacesMenu::render()
{
}