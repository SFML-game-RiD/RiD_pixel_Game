#include "GuiMainMenu.h"



void MP::GuiMainMenu::_create_buttons(sf::Texture* buttonTexture, sf::Font& aFont)
{
	std::shared_ptr<GuiButton> tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(1000, 90), sf::Vector2f(36, 0), aFont, "start");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(1000,250), sf::Vector2f(10, 0), aFont, "save game");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(1000, 400), sf::Vector2f(10, 0), aFont, "load game");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(1000, 550), sf::Vector2f(40, 0), aFont, "exit");
	_button_array.push_back(tmp);

	//std::shared_ptr<GuiButton> tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 25), sf::Vector2f(36, 0), aFont, "start");
	//_button_array.push_back(tmp);

	//tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 175), sf::Vector2f(10, 0), aFont, "save game");
	//_button_array.push_back(tmp);

	//tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 325), sf::Vector2f(10, 0), aFont, "load game");
	//_button_array.push_back(tmp);

	//tmp = std::make_shared<GuiButton>(buttonTexture, sf::Vector2f(365, 475), sf::Vector2f(40, 0), aFont, "exit");
	//_button_array.push_back(tmp);
}

MP::GuiMainMenu::GuiMainMenu()
{

}

MP::GuiMainMenu::GuiMainMenu(sf::Texture* texturePtr, sf::Texture* buttonTexture, sf::Font &aFont)
{
	aAnimation.loadObjectTextures(texturePtr, 1, 1, 1920);
	aAnimation.setObjectSpritePosition(0, 0);
	aAnimation.setOrigin(460,460);

	_create_buttons(buttonTexture,aFont);
}

void MP::GuiMainMenu::_select_button(SoundManager& aSoundManager, TaskManager& aTaskManager, sf::Vector2f guiMouseCoord)
{

	for (unsigned int i = 0; i < _button_array.size(); i++)
	{
		if (guiMouseCoord.x >=_button_array[i]->getObjectCoord().x and guiMouseCoord.x <= _button_array[i]->getObjectCoord().x + 275
			and guiMouseCoord.y >= _button_array[i]->getObjectCoord().y + 112 and guiMouseCoord.y <= _button_array[i]->getObjectCoord().y + 163)
			_button_array[i]->update(aSoundManager, aTaskManager, true);
		else
			_button_array[i]->update( aSoundManager,  aTaskManager, false);
	}
}

void MP::GuiMainMenu::_press_button(TaskManager& aMainTaskManager,  sf::RenderWindow& aMainWindow)
{
	if (_button_array[0]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::taskClickLeft,true))
	{
	
		aMainTaskManager.setState(TaskManager::stateType::stateGame);
	}
	if (_button_array[1]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::taskClickLeft, true))
	{
		
	}
	if (_button_array[2]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::taskClickLeft, true))
	{
		
	}
	if (_button_array[3]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::taskClickLeft, true))
	{
		
		aMainWindow.close();
	}
}

void MP::GuiMainMenu::update(SoundManager& aSoundManager, TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f guiMouseCoord)
{
	if (aMainTaskManager.getCurrentState() == TaskManager::stateType::stateMainMenu)
	{
		_select_button( aSoundManager, aMainTaskManager, guiMouseCoord);
		_press_button(aMainTaskManager, aMainWindow);
	}
}

void MP::GuiMainMenu::render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow)
{
	if (aMainTaskManager.getCurrentState() == TaskManager::stateType::stateMainMenu)
		_draw_menu(aMainWindow);
}
