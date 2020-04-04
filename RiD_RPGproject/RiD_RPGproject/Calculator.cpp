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

void MP::Calculator::startProcedurePlayerAnimation(TaskManager& aTaskManager, MP::Player& aPlayer, sf::Clock& aGameClock)
{
	aPlayer.playerAnimation(aGameClock, aTaskManager);
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

void MP::Calculator::startProcedureCameraZoom(TaskManager& aTaskManager, Camera& aCamera)
{
	if(aTaskManager.getTask()==MP::TaskManager::taskType::zoomIn or aTaskManager.getTask() == MP::TaskManager::taskType::zoomOut)
	aCamera.changeZoom(aTaskManager);
}

void MP::Calculator::startProcedureCorrectCamera(TaskManager& aTaskManager, sf::Vector2f newCoord, Camera& aCamera)
{
	if(aTaskManager.getTask()== MP::TaskManager::taskType::taskGoUp or
		aTaskManager.getTask() == MP::TaskManager::taskType::taskGoDown or
		aTaskManager.getTask() == MP::TaskManager::taskType::taskGoRight or
		aTaskManager.getTask() == MP::TaskManager::taskType::taskGoLeft)
	aCamera.changeCamera(newCoord);
}

void MP::Calculator::startProcedureComputerPlayer(MP::ComputerPlayer& aComputerPlayer, sf::Clock& aGameClock,Map &aMap)
{
	aComputerPlayer.getNextTask(aMap);
	aComputerPlayer.computerPlayerAnimation(aGameClock);
	aComputerPlayer.computerPlayerMove(aGameClock);
}

