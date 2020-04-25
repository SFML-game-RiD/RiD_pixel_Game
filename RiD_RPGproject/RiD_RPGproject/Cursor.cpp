#include "Cursor.h"
#include <iostream>
void MP::Cursor::setGameCoord(sf::Vector2f gameCoord)
{
	_game_coord = gameCoord;
}

sf::Vector2f MP::Cursor::getGameCoord()
{
	return _game_coord;
}

void MP::Cursor::setGuiCoord(sf::Vector2f guiCoord)
{
	_gui_coord = guiCoord;
}

sf::Vector2f MP::Cursor::getGuiCoord()
{
	return _gui_coord;
}

MP::Cursor::Cursor(sf::Texture* texturePtr)
{
	aAnimation.loadObiectTextures(texturePtr, 1, 1, 60);
	aAnimation.setOrigin(18, 15);//Don't change it !
}

void MP::Cursor::updateCursor(TaskManager& aTaskManager, Camera& aCamera)
{
	//saving gui cursor coord for drawing 
	aCamera.changeViewToGui();
	sf::Vector2f guiMouseCoord = aCamera.getWindow().mapPixelToCoords(sf::Mouse::getPosition(aCamera.getWindow()));
	setObiectCoord(guiMouseCoord);

	//Maping to pixel from gui view
	sf::Vector2i screenMouseCoord = sf::Mouse::getPosition(aCamera.getWindow());

	//Mapin from pixel to game view
	aCamera.changeViewToGame();
	sf::Vector2f gameMouseCoord = aCamera.getWindow().mapPixelToCoords(screenMouseCoord);

	setGameCoord(gameMouseCoord);
	setGuiCoord(guiMouseCoord);

}

void MP::Cursor::checkIfPlayerClicked(TaskManager& aTaskManager, Camera& aCamera)
{
	if (aTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft) //instructions below managing cursor behaviour
	{
		if (_gui_coord.x < 1040) // PROTOTYPE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! it fixed path creating on gui bar 
		{						 // changing screen width will cause bug
			if (aTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft
				and aTaskManager.getTask(TaskManager::taskRange::reply) == TaskManager::taskType::taskNone
				and aTaskManager.getTask(TaskManager::taskRange::order) == TaskManager::taskType::taskNone)
			{

				aTaskManager.setTask(TaskManager::taskRange::mainOrder, TaskManager::taskType::taskAutoMove);
				aTaskManager.setTask(TaskManager::taskRange::order, TaskManager::taskType::taskCreateAutoPath);

			}
			else if (aTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft
				and aTaskManager.getTask(TaskManager::taskRange::reply) == TaskManager::taskType::taskWaitForDoubleClickLeft
				and aTaskManager.getTask(TaskManager::taskRange::order) == TaskManager::taskType::taskNone)
			{

				aTaskManager.setTask(TaskManager::taskRange::mainOrder, TaskManager::taskType::taskAutoMove);
				aTaskManager.setTask(TaskManager::taskRange::order, TaskManager::taskType::taskDoubleClickLeft);
			}

			else if (aTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft
				and aTaskManager.getTask(TaskManager::taskRange::order) == TaskManager::taskType::taskExecuteAutoMove)
			{
				aTaskManager.setTask(TaskManager::taskRange::mainOrder, TaskManager::taskType::taskAutoMove);
				aTaskManager.setTask(TaskManager::taskRange::order, TaskManager::taskType::taskBreakAutoMove);
			}
			else if (aTaskManager.getTask(TaskManager::taskRange::mainOrder) == TaskManager::taskType::taskClickLeft
				and aTaskManager.getTask(TaskManager::taskRange::order) == TaskManager::taskType::taskBreakAutoMove)
			{
				aTaskManager.setTask(TaskManager::taskRange::mainOrder, TaskManager::taskType::taskAutoMove);
				aTaskManager.setTask(TaskManager::taskRange::order, TaskManager::taskType::taskBreakAutoMove);
			}
		}
	}
}

void MP::Cursor::update(TaskManager& aMainTaskManager, Camera& aCamera)
{
	updateCursor(aMainTaskManager, aCamera);
	checkIfPlayerClicked(aMainTaskManager, aCamera);
}

void MP::Cursor::render()
{
}
