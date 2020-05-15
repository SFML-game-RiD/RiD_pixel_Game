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
	aAnimation.loadObjectTextures(texturePtr, 1, 1, 60);
	aAnimation.setOrigin(18, 15);//Don't change it !
}

void MP::Cursor::_update_cursor(TaskManager& aTaskManager, Camera& aCamera)
{
	//saving gui cursor coord for drawing 
	aCamera.changeViewToGui();
	sf::Vector2f guiMouseCoord = aCamera.getWindow().mapPixelToCoords(sf::Mouse::getPosition(aCamera.getWindow()));
	setObjectCoord(guiMouseCoord);

	//Maping to pixel from gui view
	sf::Vector2i screenMouseCoord = sf::Mouse::getPosition(aCamera.getWindow());

	//Mapin from pixel to game view
	aCamera.changeViewToGame();
	sf::Vector2f gameMouseCoord = aCamera.getWindow().mapPixelToCoords(screenMouseCoord);

	setGameCoord(gameMouseCoord);
	setGuiCoord(guiMouseCoord);

}

void MP::Cursor::_check_if_player_clicked(TaskManager& aTaskManager, Camera& aCamera)
{
	if (aTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON,false)) //instructions below managing cursor behaviour
	{
		if (aTaskManager.getCurrentState() == TaskManager::stateType::stateGame)
		{
			if (_gui_coord.x < 1040 and _gui_coord.x>-460) //map
			{
				if (aTaskManager.findTask(TaskNode::taskType::TASK_EXECUTE_AUTO_MOVE, false))//for break auto move
					aTaskManager.addTask(TaskNode::taskType::TASK_BREAK_AUTO_MOVE);
				else if (aTaskManager.findTask(TaskNode::taskType::TASK_WAIT_FOR_LEFT_DOUBLE_CLICK, true))//for start auto move after path marking
					aTaskManager.addTask(TaskNode::taskType::TASK_LEFT_DOUBLE_CLICK);
				else
				{
					aTaskManager.addTask(TaskNode::taskType::TASK_CREATE_PATH);//for start auto move procedure
					aTaskManager.addTask(TaskNode::taskType::TASK_AUTO_MOVE);
				}
			}
			else //gui
			{
				aTaskManager.addTask(TaskNode::taskType::TASK_BREAK_AUTO_MOVE);
			}
		}
	}
}

void MP::Cursor::update(TaskManager& aMainTaskManager, Camera& aCamera)
{
	_update_cursor(aMainTaskManager, aCamera);
	_check_if_player_clicked(aMainTaskManager, aCamera);
}

void MP::Cursor::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObjectSprite());
}
