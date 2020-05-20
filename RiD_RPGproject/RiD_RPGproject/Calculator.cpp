#include <thread>
#include "Calculator.h"
#include <iostream>


void MP::Calculator::_computer_players_procedure(TaskManager& aMainTaskManager, SoundManager &aSoundManager,ObjectManager& aObiectManager, sf::Clock& gameClock, Map& aMap)
{
	std::list<ComputerPlayerBandit>* computerPlayerList = aObiectManager.getComputerPlayerList();
	std::list<ComputerPlayerBandit>::iterator it;

	it = computerPlayerList->begin();

	for (it; it != computerPlayerList->end(); it++)
		it->update(aMainTaskManager,aSoundManager,aMap, gameClock,aObiectManager.getPlayer());

}

void MP::Calculator::_trees_procedure(TaskManager& aMainTaskManager, sf::Clock& globalClock, ObjectManager& aObiectManager)
{

	std::list<Tree>* aTree = aObiectManager.getTreeList();
	std::list<Tree >::iterator iterator;
	iterator = aTree->begin();



	for (iterator; iterator != aTree->end(); iterator++)
		if (aObiectManager.access())
			iterator->update(aMainTaskManager,globalClock);

}


void MP::Calculator::updateGame(SoundManager& aSoundManager, TaskManager& aMainTaskManager, ObjectManager& aObiectManager, sf::Clock& gameClock, Camera& aCamera)
{
	//state

	aMainTaskManager.updateState();

	//game
	aObiectManager.getPlayer()->update(aSoundManager, aMainTaskManager, gameClock, aObiectManager.getMap(), aObiectManager.getCursor()->getGameCoord());

	_trees_procedure(aMainTaskManager, gameClock, aObiectManager);

	_computer_players_procedure(aMainTaskManager, aSoundManager, aObiectManager, gameClock, aObiectManager.getMap());

	//menu
	aObiectManager.getGuiManager().getMapGui()->update(aMainTaskManager, aObiectManager.getPlayer()->aItemsManager, aObiectManager.getPlayer()->getMessage());

	aObiectManager.getGuiManager().getGuiMainMenu()->update(aSoundManager, aMainTaskManager, aCamera.getWindow(), aObiectManager.getCursor()->getGuiCoord());

	aObiectManager.getGuiManager().getGuiPlacesMenu()->update(aSoundManager, aMainTaskManager, aCamera.getWindow(), aObiectManager.getCursor()->getGuiCoord());

	aObiectManager.getGuiManager().getGuiMarketPlace()->update(aSoundManager, aMainTaskManager, aCamera.getWindow(), aObiectManager.getCursor()->getGuiCoord(), aObiectManager.getPlayer(), aObiectManager.getPlayer()->getCurrentPlace());
}