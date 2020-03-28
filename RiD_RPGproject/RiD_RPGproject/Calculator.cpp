#include "Calculator.h"


void MP::Calculator::startProcedurePlayerMove(TaskManager& aTaskManager, MP::Player& aPlayer, sf::Clock& aGameClock)
{
	MapMove tmp;

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

void MP::Calculator::startProcedureTreesAnimation(sf::Clock& globalClock,ObiectManager &aObiectManager)
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
