#include "Calculator.h"
#include <iostream>


void MP::Calculator::_computer_players_procedure(SoundManager &aSoundManager,ObjectManager& aObiectManager, sf::Clock& gameClock, Map& aMap)
{
	std::list<ComputerPlayerBandit>* computerPlayerList = aObiectManager.getComputerPlayerList();
	std::list<ComputerPlayerBandit>::iterator it;

	it = computerPlayerList->begin();

	for (it; it != computerPlayerList->end(); it++)
		it->update(aSoundManager,aMap, gameClock,aObiectManager.getPlayer());
}

void MP::Calculator::_trees_procedure(sf::Clock& globalClock, ObjectManager& aObiectManager)
{
	std::list<Tree>* aTree = aObiectManager.getTreeList();
	std::list<Tree >::iterator iterator;
	iterator = aTree->begin();

	for (iterator; iterator != aTree->end(); iterator++)
		if (aObiectManager.access())
			iterator->update(globalClock);
}


void MP::Calculator::startMainGameProcedures(SoundManager & aSoundManager, TaskManager& aMainTaskManager, ObjectManager& aObiectManager, sf::Clock& gameClock, Camera& aCamera)
{
	aObiectManager.getPlayer()->update(aSoundManager,aMainTaskManager, gameClock, aObiectManager.getMap(), aObiectManager.getCursor()->getGameCoord());

	_trees_procedure(gameClock, aObiectManager);

	aCamera.update(aObiectManager.getPlayer()->getObjectCoord(), aMainTaskManager);

	_computer_players_procedure(aSoundManager,aObiectManager, gameClock, aObiectManager.getMap());

	aObiectManager.getCursor()->update(aMainTaskManager, aCamera);

	aObiectManager.getGuiManager().getMapGui()->update(aObiectManager.getPlayer()->aItemsManager);
}

void MP::Calculator::startMenuProcedures(SoundManager& aSoundManager, TaskManager &aMainTaskManager, ObjectManager & aObiectManager,Camera& aCamera)
{

	aObiectManager.getGuiManager().getGuiMainMenu()->update(aSoundManager,aMainTaskManager, aCamera.getWindow(), aObiectManager.getCursor()->getGuiCoord());

	aObiectManager.getGuiManager().getGuiPlacesMenu()->update(aSoundManager,aMainTaskManager, aCamera.getWindow(), aObiectManager.getCursor()->getGuiCoord());

	aObiectManager.getGuiManager().getGuiMarketPlace()->update(aSoundManager,aMainTaskManager, aCamera.getWindow(), aObiectManager.getCursor()->getGuiCoord(), aObiectManager.getPlayer(), aObiectManager.getPlayer()->getCurrentPlace());

	aObiectManager.getCursor()->update(aMainTaskManager, aCamera);
	
	aMainTaskManager.deleteTaskList();
}

