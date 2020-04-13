#include "Calculator.h"
#include <iostream>

void MP::Calculator::_start_procedure_player_move(MP::Player& aPlayer, sf::Clock& aGameClock, TaskManager& aMainTaskManager)
{
	Move tmp;

	switch (aMainTaskManager.getTask(MP::TaskManager::taskRange::order))
	{
	case(MP::TaskManager::taskType::taskGoUp):
		tmp.moveBlockUp(aPlayer, aGameClock,aMainTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoLeft):
		tmp.moveBlockLeft(aPlayer, aGameClock,  aMainTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoDown):
		tmp.moveBlockDown(aPlayer, aGameClock,  aMainTaskManager);
		break;
	case(MP::TaskManager::taskType::taskGoRight):
		tmp.moveBlockRight(aPlayer, aGameClock, aMainTaskManager);
		break;
	default:
	{
		aPlayer.resetBlockLenghtCopy();
	}

	}
}

void MP::Calculator::_start_procedure_player_animation(MP::Player& aPlayer, sf::Clock& aGameClock, TaskManager& aMainTaskManager)
{
	aPlayer.playerAnimation(aGameClock, aMainTaskManager);
}

void MP::Calculator::_start_procedure_camera_zoom(ObiectManager & aObiectManager,TaskManager& aTaskManager, Camera& aCamera)
{
	if (aTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskZoomIn or aTaskManager.getTask(MP::TaskManager::taskRange::order) == MP::TaskManager::taskType::taskZoomOut)
		aCamera.changeZoom(aTaskManager);
}

void MP::Calculator::_start_procedure_correct_camera( sf::Vector2f newCoord, Camera& aCamera)
{
		aCamera.changeCamera(newCoord);
}

void MP::Calculator::_start_procedure_player_auto_or_normal_move(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, sf::Clock& aGameClock)
{
	switch (aMainTaskManager.getTask(MP::TaskManager::taskRange::mainOrder))
	{
	case(MP::TaskManager::taskType::taskNormalMove):
	{
		_start_procedure_player_move(*aObiectManager.getPlayer(), aGameClock, aMainTaskManager);

		_start_procedure_player_animation(*aObiectManager.getPlayer(), aGameClock, aMainTaskManager);
	}break;
	case(MP::TaskManager::taskType::taskAutoMove):
	{



		switch (aMainTaskManager.getTask(MP::TaskManager::taskRange::order))
		{
		case(MP::TaskManager::taskType::taskCreateAutoPath):
		{
			//geting start and stop coordinates

			MapElement* start = aObiectManager.getMap().findElementAddressSquareRange(aObiectManager.getPlayer()->getObiectCoord(), aObiectManager.getMapElementHead());

			MapElement* stop = aObiectManager.getMap().findElementAddressSquareRange(aObiectManager.getCursor()->getGameCoord(), aObiectManager.getMapElementHead());

			if (stop->isWalkable())
			{
				if (start->getLandTile().getObiectCoord() != stop->getLandTile().getObiectCoord())
				{

					checkingVector = stop->getLandTile().getObiectCoord();

					//creating path
					MP::PathCreator  tmp(aObiectManager.getMap());

					aMainTaskManager.setTask(MP::TaskManager::taskRange::reply, MP::TaskManager::taskType::taskWaitForDoubleClickLeft); //computer waiting for player reply
					aObiectManager.getPlayer()->setPath(tmp.findPath(start->getLandTile().getObiectCoord(), stop->getLandTile().getObiectCoord()));

					aObiectManager.getPlayer()->markPath();
				}

			}


			aMainTaskManager.endTask(MP::TaskManager::taskRange::order);
			aMainTaskManager.endTask(MP::TaskManager::taskRange::mainOrder);


		}break;
		case(MP::TaskManager::taskType::taskBreakAutoMove)://breaks auto move
		{
			if (aObiectManager.getPlayer()->aPawnObiectTaskManager.getTask(TaskManager::taskRange::order) != TaskManager::taskType::taskNone)
			{
				aObiectManager.getPlayer()->playerAutoAnimation(aGameClock);
				aObiectManager.getPlayer()->playerAutoMove(aGameClock);
			}
			else
			{
				aObiectManager.getPlayer()->deletePlayerPath();
				aMainTaskManager.resetOrdersAndReply();
			}
		}break;
		case(MP::TaskManager::taskType::taskExecuteAutoMove)://execute auto move		
		{
			aObiectManager.getPlayer()->playerAutomaticMove(aObiectManager.getMap(), aMainTaskManager);
			aObiectManager.getPlayer()->playerAutoAnimation(aGameClock);
			aObiectManager.getPlayer()->playerAutoMove(aGameClock);

		}break;
		case(MP::TaskManager::taskType::taskDoubleClickLeft)://starts procedure auto move if player clicked second time
		{

			MapElement* checkingElement = aObiectManager.getMap().findElementAddressSquareRange(aObiectManager.getCursor()->getGameCoord(), aObiectManager.getMapElementHead());

			if (checkingElement->getLandTile().getObiectCoord().x == checkingVector.x and checkingElement->getLandTile().getObiectCoord().y == checkingVector.y)
			{
				aObiectManager.getPlayer()->unmarkPath();
				aMainTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskExecuteAutoMove);
			}
			else
			{
				aMainTaskManager.setTask(MP::TaskManager::taskRange::order, MP::TaskManager::taskType::taskBreakAutoMove);
				aObiectManager.getPlayer()->unmarkPath();
			}
		}break;
		}
	}break;

	}
}

void MP::Calculator::_start_procedure_main_menu(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, Camera& aCamera)
{
	aObiectManager.getGuiManager().getGuiMainMenu()->selectButton(aObiectManager.getCursor()->getGuiCoord());
	aObiectManager.getGuiManager().getGuiMainMenu()->pressButton(aMainTaskManager, aCamera.getWindow());
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

	_start_procedure_correct_camera(newCoord, aCamera);
}

void MP::Calculator::startProcedureCursor(TaskManager& aTaskManager, ObiectManager& aObiectManager, Camera& aCamera)
{
	aObiectManager.getCursor()->updateCursor(aTaskManager,aCamera);

	aObiectManager.getCursor()->checkIfPlayerClicked(aTaskManager, aCamera);
}

void MP::Calculator::startMainGameProcedures(TaskManager& aMainTaskManager, ObiectManager& aObiectManager, sf::Clock& globalClock, Camera& aCamera)
{
	startProcedurePlayer(aMainTaskManager, aObiectManager, globalClock);

	startProcedureTrees(globalClock, aObiectManager);

	startProcedureCamera(aObiectManager, aMainTaskManager,aObiectManager.getPlayer()->getObiectCoord(), aCamera);

	startProcedureComputerPlayers(aObiectManager, globalClock, aObiectManager.getMap());

	startProcedureCursor(aMainTaskManager, aObiectManager, aCamera);

	startProcedureMapGui(aObiectManager);
}

void MP::Calculator::startProcedureMapGui(ObiectManager& aObiectManager)
{
	aObiectManager.getPlayer();
	aObiectManager.getGuiManager().getMapGui()->updateItems(aObiectManager.getPlayer()->aItemsManager);
}

void MP::Calculator::startMainMenuProcedures(TaskManager &aMainTaskManager, ObiectManager & aObiectManager,Camera& aCamera)
{
	_start_procedure_main_menu(aMainTaskManager,aObiectManager,aCamera);

	startProcedureCursor(aMainTaskManager, aObiectManager, aCamera);
}

void MP::Calculator::startPlacesProcedures()
{
}

