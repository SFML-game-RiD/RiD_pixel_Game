#include "GuiMainMenu.h"



void MP::GuiMainMenu::_create_buttons(RiD::AssetManager& aAssetManager)
{
	std::shared_ptr<GuiButton> tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(1000, 90), sf::Vector2f(36, 0), "start");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(1000,250), sf::Vector2f(10, 0), "save game");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(1000, 400), sf::Vector2f(10, 0), "load game");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(1000, 550), sf::Vector2f(40, 0), "exit");
	_button_array.push_back(tmp);
}

MP::GuiMainMenu::GuiMainMenu()
{

}

MP::GuiMainMenu::GuiMainMenu(RiD::AssetManager& aAssetManager)
{
	aAnimation.loadObjectTextures(&aAssetManager.getTexture("menu"), 1, 1, 1920);
	aAnimation.setObjectSpritePosition(0, 0);
	aAnimation.setOrigin(460,460);

	_create_buttons(aAssetManager);
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
	if (_button_array[0]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON,true))
	{
	
		aMainTaskManager.setState(TaskManager::stateType::stateGame);
	}
	if (_button_array[1]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		
	}
	if (_button_array[2]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		
	}
	if (_button_array[3]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
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
