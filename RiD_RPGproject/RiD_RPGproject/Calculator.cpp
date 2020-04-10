#include "Calculator.h"
#include <iostream>

void MP::Calculator::_start_procedure_player_move(TaskManager& aTaskManager, MP::Player& aPlayer, sf::Clock& aGameClock)
{
	Move tmp;

	switch (aTaskManager.getTask())
	{
	case(MP::TaskManager::taskType::taskGoUp):
		tmp.moveBlockUp(aPlayer, aGameClock, aTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoLeft):
		tmp.moveBlockLeft(aPlayer, aGameClock, aTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoDown):
		tmp.moveBlockDown(aPlayer, aGameClock, aTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoRight):
		tmp.moveBlockRight(aPlayer, aGameClock, aTaskManager);
		break;
	default:
	{
		aPlayer.resetBlockLenghtCopy();
	}

	}
}

void MP::Calculator::_start_procedure_player_animation(TaskManager& aTaskManager, MP::Player& aPlayer, sf::Clock& aGameClock)
{
	aPlayer.playerAnimation(aGameClock, aTaskManager);
}

void MP::Calculator::_start_procedure_camera_zoom(ObiectManager & aObiectManager,TaskManager& aTaskManager, Camera& aCamera)
{
	if (aTaskManager.getTask() == MP::TaskManager::taskType::taskZoomIn or aTaskManager.getTask() == MP::TaskManager::taskType::taskZoomOut)
		aCamera.changeZoom(aTaskManager);
}

void MP::Calculator::_start_procedure_correct_camera(ObiectManager& aObiectManager, TaskManager& aTaskManager, sf::Vector2f newCoord, Camera& aCamera)
{
	if (aTaskManager.getTask() != MP::TaskManager::taskType::taskNone)
		aCamera.changeCamera(newCoord);
}

void MP::Calculator::_start_procedure_player_auto_or_normal_move(TaskManager& aTaskManager, ObiectManager& aObiectManager, sf::Clock& aGameClock)
{
	if (aTaskManager.getMouseTask() == MP::TaskManager::taskType::taskNone) //keyboard move
	{
		_start_procedure_player_move(aTaskManager, *aObiectManager.getPlayer(), aGameClock);

		_start_procedure_player_animation(aTaskManager, *aObiectManager.getPlayer(), aGameClock);
	}
	else if (aTaskManager.getMouseTask() == MP::TaskManager::taskType::taskClickLeft and aTaskManager.getTask() == MP::TaskManager::taskType::taskNone) //creates path
	{
		//geting start and stop coordinates

		MapElement* start = aObiectManager.getMap().findElementAddressSquareRange(aObiectManager.getPlayer()->getObiectCoord(), aObiectManager.getMapElementHead());

		MapElement* stop = aObiectManager.getMap().findElementAddressSquareRange(aObiectManager.getCursor()->getGuiCoord(), aObiectManager.getMapElementHead());

		if (stop->isWalkable())
		{
			if (start->getLandTile().getObiectCoord() != stop->getLandTile().getObiectCoord())
			{

				checkingVector = stop->getLandTile().getObiectCoord();

				//creating path
				MP::PathCreator  tmp(aObiectManager.getMap());

				aTaskManager.startProcedureWaitForDoubleClick();

				aObiectManager.getPlayer()->setPath(tmp.findPath(start->getLandTile().getObiectCoord(), stop->getLandTile().getObiectCoord()));

				aObiectManager.getPlayer()->markPath();
			}
			else
			{
				aTaskManager.endMouseTask();
			}
		}
		else
		{
			aTaskManager.endMouseTask();
		}

	}
	else if (aTaskManager.getMouseTask() == MP::TaskManager::taskType::taskClickLeft and aTaskManager.getTask() == MP::TaskManager::taskType::taskAutoMove and aObiectManager.getPlayer()->aPlayerTaskManager.getTask() == MP::TaskManager::taskType::taskNone)//breaks auto move
	{
		aObiectManager.getPlayer()->deletePlayerPath();
		aTaskManager.endMouseTask();
		aTaskManager.endTask();
	}
	else if (aTaskManager.getTask() == MP::TaskManager::taskType::taskAutoMove or aObiectManager.getPlayer()->aPlayerTaskManager.getTask() != MP::TaskManager::taskType::taskNone)//execute auto move
	{
		aObiectManager.getPlayer()->playerAutomaticMove(aObiectManager.getMap(), aTaskManager);

		aObiectManager.getPlayer()->playerAutoAnimation(aGameClock);

		aObiectManager.getPlayer()->playerAutoMove(aGameClock);
	}
	else if (aTaskManager.getMouseTask() == MP::TaskManager::taskType::taskDoubleClickLeft)//starts procedure auto move if player clicked second time
	{

		MapElement* checkingElement = aObiectManager.getMap().findElementAddressSquareRange(aObiectManager.getCursor()->getObiectCoord(), aObiectManager.getMapElementHead());

		if (checkingElement->getLandTile().getObiectCoord().x == checkingVector.x and checkingElement->getLandTile().getObiectCoord().y == checkingVector.y)
		{

			aObiectManager.getPlayer()->unmarkPath();

			aTaskManager.startProcedureAutoMove();
		}
		else
		{
			aTaskManager.endMouseTask();
			aTaskManager.endTask();
			aObiectManager.getPlayer()->unmarkPath();
		}
	}

}

void MP::Calculator::startProcedurePlayer(TaskManager& aTaskManager, ObiectManager& aObiectManager, sf::Clock& aGameClock)
{
	_start_procedure_player_auto_or_normal_move(aTaskManager, aObiectManager, aGameClock);
}

void MP::Calculator::startProcedureTrees(sf::Clock& globalClock,ObiectManager &aObiectManager)
{
	std::list<Tree>* aTree = aObiectManager.getTreeList();
	std::list<Tree >::iterator iterator;
	iterator = aTree->begin();

	for (int i = 0; i < aTree->size(); i++)
	{
		if (aObiectManager._access())
			iterator->treeAnimation(globalClock);
		iterator++;
	}
}

void MP::Calculator::startProcedureComputerPlayers(ObiectManager& aObiectManager, sf::Clock& aGameClock, Map& aMap)
{
	std::list<ComputerPlayer> *computerPlayerList = aObiectManager.getComputerPlayerList();
	std::list<ComputerPlayer>::iterator it;

	it = computerPlayerList->begin();

	for (it; it != computerPlayerList->end(); it++)
	{
		it->getNextTask(aMap);
		it->computerPlayerAnimation(aGameClock);
		it->computerPlayerMove(aGameClock);
	}
}

void MP::Calculator::startProcedureCamera(ObiectManager& aObiectManager, TaskManager& aTaskManager, sf::Vector2f newCoord, Camera& aCamera)
{
	
	_start_procedure_camera_zoom(aObiectManager, aTaskManager, aCamera);

	_start_procedure_correct_camera(aObiectManager, aTaskManager, newCoord, aCamera);
}

void MP::Calculator::startProcedureCursor(TaskManager& aTaskManager, ObiectManager& aObiectManager, Camera& aCamera)
{
	//saving gui cursor coord for drawing 
	aCamera.changeViewToGui();
	sf::Vector2f guiMouseCoord = aCamera.getWindow().mapPixelToCoords(sf::Mouse::getPosition(aCamera.getWindow()));
	aObiectManager.getCursor()->setObiectCoord(guiMouseCoord);
	
	//Maping to pixel from gui view
	sf::Vector2i screenMouseCoord = sf::Mouse::getPosition(aCamera.getWindow());

	//Mapin from pixel to game view
	aCamera.changeViewToGame();
	sf::Vector2f gameMouseCoord = aCamera.getWindow().mapPixelToCoords(screenMouseCoord);
	aObiectManager.getCursor()->saveGuiCoord(gameMouseCoord);
	if (aTaskManager.getMouseTask() == MP::TaskManager::taskType::taskClickLeft)
	{
		//TO DO ...
	}
	if(aTaskManager.getMouseTask() == MP::TaskManager::taskType::taskClickRight)
	{ 
		//TO DO ...
	}

}

